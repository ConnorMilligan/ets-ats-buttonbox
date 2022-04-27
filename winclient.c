/*
	Create a TCP socket
*/
//cl winclient.c

#include<stdio.h>
#include<winsock2.h>
#include<WinUser.h>

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"user32.lib")

int main(int argc , char *argv[])
{
	WSADATA wsa;
	SOCKET s;
	struct sockaddr_in server;
	char *message , server_reply[1024];
	int recv_size;

    INPUT inputs[2];
    ZeroMemory(inputs, sizeof(inputs));

    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = 0x4C;
    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = 0x4C;
    inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("Failed. Error Code : %d",WSAGetLastError());
		return 1;
	}
	
	printf("Initialised.\n");
	
	//Create a socket
	if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d" , WSAGetLastError());
	}

	printf("Socket created.\n");
	
	
	server.sin_addr.s_addr = inet_addr("192.168.1.10");
	server.sin_family = AF_INET;
	server.sin_port = htons( 8080 );

	//Connect to remote server
	if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}
	
	printf("Connected\n");
	//Receive a reply from the server
	for (;;) {
		(recv_size = recv(s , server_reply , 2000 , 0));
		if (server_reply[0] == 49) {
			printf("%s\n", server_reply);
			// Press pageup key
			keybd_event( VK_PRIOR, 0x49, KEYEVENTF_EXTENDEDKEY | 0, 0 );
			// Simulate a key release
			keybd_event( VK_PRIOR, 0x49, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
		}
		else if (server_reply[0] == 50) {
			printf("%s\n", server_reply);
			// Press pageup key
			keybd_event( VK_NEXT, 0x51, KEYEVENTF_EXTENDEDKEY | 0, 0 );
			// Simulate a key release
			keybd_event( VK_NEXT, 0x51, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
		}
		 else if (server_reply[0] == 51) {
			printf("%s\n", server_reply);
			// Press end key
			keybd_event( VK_END, 0x4F, KEYEVENTF_EXTENDEDKEY | 0, 0 );
			// Simulate a key release
			keybd_event( VK_END, 0x4F, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
		}
		else if (server_reply[0] == 52) {
			printf("%s\n", server_reply);
			// Press home key
			keybd_event( VK_HOME, 0x24, KEYEVENTF_EXTENDEDKEY | 0, 0 );
			// Simulate a key release
			keybd_event( VK_HOME, 0x24, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
		}
		else if (server_reply[0] == 53) {
			printf("%s\n", server_reply);
			// Press insert key
			keybd_event( VK_INSERT, 0x52, KEYEVENTF_EXTENDEDKEY | 0, 0 );
			// Simulate a key release
			keybd_event( VK_INSERT, 0x52, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			
		}
		else if (server_reply[0] == 54) {
			printf("%s\n", server_reply);
			// Press delete key 
			keybd_event( VK_DELETE, 0x53, KEYEVENTF_EXTENDEDKEY | 0, 0 );
			// Simulate a key release
			keybd_event( VK_DELETE, 0x53, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
		}
		

		//clear the server_reply buffer
		for (int i = 0; i<1024; i++) {
			server_reply[i] = 0;
		}
	}

	return 0;
}