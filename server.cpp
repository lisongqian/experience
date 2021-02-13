/***************************************
 *
 * Created by LiSongqian on 2021/1/4.
 * TCP服务端
 *
 **************************************/
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <WinSock2.h>
#include <cstdio>
#include <cstdlib>

using namespace std;
#pragma comment(lib, "ws2_32.lib")

int		port;

int tcpServer()
{
	WSADATA wsaData;

	char buf[] = "Server: hello, I am a server.....";

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("Failed to load Winsock");
		return 1;
	}

	//创建用于监听的套接字
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(port); //1024以上的端口号
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	int retVal = bind(sockSrv, (LPSOCKADDR)&addrSrv, sizeof(SOCKADDR_IN));
	if (retVal == SOCKET_ERROR){
		printf("Failed bind:%d\n", WSAGetLastError());
		return 1;
	}
	cout << "Listen to port " << port << "." << endl;
	if (listen(sockSrv, 10) == SOCKET_ERROR){
		printf("Listen failed:%d", WSAGetLastError());
		return 1;
	}

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);

//等待客户请求到来
	SOCKET sockConn = accept(sockSrv, (SOCKADDR *)&addrClient, &len);
	if (sockConn == SOCKET_ERROR){
		printf("Accept failed:%d", WSAGetLastError());
		//break;
	}

	printf("Accept client IP:[%s]\n", inet_ntoa(addrClient.sin_addr));

	//发送数据
	int iSend = send(sockConn, buf, sizeof(buf), 0);
	if (iSend == SOCKET_ERROR){
		printf("send failed");
		// break;
	}

	char recvBuf[100];
	memset(recvBuf, 0, sizeof(recvBuf));
	//         //接收数据
	recv(sockConn, recvBuf, sizeof(recvBuf), 0);
	printf("%s\n", recvBuf);

	closesocket(sockConn);


	closesocket(sockSrv);
	WSACleanup();
	system("pause");
	return 0;
}
int udpServer(){ return 0; }

int main()
{
	cout << "1:TCP" << endl;
	cout << "2:UDP" << endl;

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