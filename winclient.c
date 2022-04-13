/*
	Create a TCP socket
*/

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
		if (server_reply[0] != 0) {
			printf("%s\n", server_reply);
            UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
			for (int i = 0; i<1024; i++) {
				server_reply[i] = 0;
			}
		}
	}

	return 0;
}