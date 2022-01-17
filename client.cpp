/***************************************
*
* Created by LiSongqian on 2021/1/4.
* TCP服务端
*
**************************************/
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <WinSock2.h>
#include <cstdio>
#include <cstdlib>

using namespace std;
#pragma comment(lib, "ws2_32.lib")

char	ip[16];
int		port;

int tcpServer()
{
	//加载套接字
	WSADATA wsaData;
	char buff[1024];
	memset(buff, 0, sizeof(buff));

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("Failed to load Winsock");
		return 1;
	}

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(port);
	addrSrv.sin_addr.S_un.S_addr = inet_addr(ip);

	//创建套接字
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);
	if (SOCKET_ERROR == sockClient){
		printf("Socket() error:%d", WSAGetLastError());
		return 1;
	}

	//向服务器发出连接请求
	if (connect(sockClient, (struct  sockaddr*)&addrSrv, sizeof(addrSrv)) == INVALID_SOCKET){
		printf("Connect failed:%d", WSAGetLastError());
		return 1;
	}
	else
	{
		//接收数据
		recv(sockClient, buff, sizeof(buff), 0);
		printf("%s\n", buff);
	}

	//发送数据
	char *buffSend = "hello, this is a Client....";
	send(sockClient, buffSend, strlen(buffSend) + 1, 0);
	printf("%d", strlen(buffSend) + 1);

	//关闭套接字
	closesocket(sockClient);
	WSACleanup();
	system("pause");
	return 0;
}
int udpServer(){ return 0; }

int main()
{
	cout << "1:TCP" << endl;
	cout << "2:UDP" << endl;
	strncpy(ip, "127.0.0.1", sizeof(ip) - 1);
	port = 5009;
	int a;
	cin >> a;
	if (1 == a)
	{
		tcpServer();
	}
	else if (2 == a)
	{
		udpServer();
	}
	return 0;
}