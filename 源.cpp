#include<winsock.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#pragma comment(lib,"ws2_32.lib")
SOCKET sockSer, sockCli;
SOCKADDR_IN addSer, addCli;
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
	sockSer = socket(AF_INET, SOCK_STREAM, 0);//af(address fimaly)inet(ipv4),sock_stream(tcp)
	addSer.sin_family = AF_INET;//sin(socket in)
	addSer.sin_addr.S_un.S_addr = INADDR_ANY;
	addSer.sin_port = htons(12345);
	bind(sockSer, (sockaddr *)&addSer, sizeof(addSer));



	//listen(sockSer, 5);//3-5
	//cout << "#####服务端已启动#####" << endl;
	//sockCli = accept(sockSer, (sockaddr *)&addCli, &size);
	//if (sockCli != INVALID_SOCKET)  //也可用NULL判断
	//{
	//	printf("IP地址为%s的服务器已连接\n", inet_ntoa(addCli.sin_addr));
	//	send(sockCli, "您已成功与服务器连接", sizeof("您已成功与服务器连接"), 0);
	//}

	while(1)
	{
		listen(sockSer, 5);//3-5
		cout << "#####服务端已启动#####" << endl;
		sockCli = accept(sockSer, (sockaddr *)&addCli, &size);
		if (sockCli != INVALID_SOCKET)  //也可用NULL判断
		{
			printf("IP地址为%s的服务器已连接\n", inet_ntoa(addCli.sin_addr));
			send(sockCli, "您已成功与服务器连接", sizeof("您已成功与服务器连接"), 0);
			while (1)
			{
				recv(sockCli, recvbuf, sizeof(recvbuf), 0);
				if(strlen(recvbuf) != 0)
				{ 

				    cout << "Client:";
					cout << recvbuf << endl;
					if (strcmp(recvbuf, "exit") == 0)
					{
						cout << "客户端已退出" << endl;
						break;
						//return 0;
					}
					cout << "Server:";
					cin >> input;
				    send(sockCli, input, strlen(input)+1, 0);
				    if (strcmp(input, "exit") == 0 )
				    {
					    break;
					   //return 0;
				    }
				}

			}
		}

	/*	sockCli = accept(sockSer, (sockaddr *)&addCli, &size);
		recv(sockSer, recvbuf, sizeof(recvbuf), 0);
		cout << "Client:";
		cout << recvbuf << endl << "Server:";
		cin >> input;
		send(sockCli, input, strlen(input), 0);
		if (strcmp(input, "exit") == 0)
		{
			return 0;
		}*/

	}
    
	closesocket(sockSer);
	closesocket(sockCli);
	WSACleanup();
	system("pause");
	return 0;
}