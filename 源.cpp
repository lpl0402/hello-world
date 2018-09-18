#include<winsock.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
#pragma comment(lib,"ws2_32.lib")
SOCKET sockSer,sockCli;
SOCKADDR_IN addSer,addCli;
const int buf_len = 2048;
char input[buf_len];
char recvbuf[buf_len];
int main()
{
	WSADATA data;
	int size = sizeof(SOCKADDR_IN);
	if (WSAStartup(MAKEWORD(2, 0), &data) != 0)
	{
		cout << "载入socket库失败！" << endl;
		system("pause");
		return 0;
	}
	sockCli = socket(AF_INET, SOCK_STREAM, 0);//af(address fimaly)inet(ipv4),sock_stream(tcp)
	addCli.sin_family = AF_INET;//sin(socket in)
	addCli.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addCli.sin_port = htons(12345);


	//sockSer = socket(AF_INET, SOCK_STREAM, 0);//af(address fimaly)inet(ipv4),sock_stream(tcp)
	//addSer.sin_family = AF_INET;//sin(socket in)
	//addSer.sin_addr.S_un.S_addr = INADDR_ANY;
	//addSer.sin_port = htons(12345);

	if (connect(sockCli, (sockaddr *)&addCli, size) != SOCKET_ERROR)
	{
		while (1)
		{
			memset(recvbuf, buf_len, sizeof(recvbuf));
			recv(sockCli, recvbuf, sizeof(recvbuf), 0);
			cout << "Server:";
			cout << recvbuf << endl << "Client:";
			cin >> input;
			send(sockCli, input, strlen(input)+1, 0);
			if (strcmp(input, "exit") == 0)
			{
				break;
			}
		}
	}
	cout << "感谢本次连接" << endl;
	closesocket(sockCli);
	WSACleanup();
	system("pause");
	return 0;

}