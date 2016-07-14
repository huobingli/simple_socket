#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#ifndef PARAM
#define PARAM
	#include "param.h"
#endif

//#include "param.h"
using namespace std;


class serverSocket {
private:
	int iSocket;
	int iPort;
public:
	serverSocket(int iport) {
		iSocket = 0;
		iPort = iport;
	}

	~serverSocket() {}

	void createServerSocket() {
		iSocket = socket(AF_INET, SOCK_STREAM, 0);
		int on = 1;
		if(setsockopt(iSocket, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1) {
			cout<<"setsockopt failed "<<strerror(errno);
		}
		struct sockaddr_in addr;
		memset(&addr, 0, sizeof(addr));

		addr.sin_family = AF_INET;
		addr.sin_port = htons(iPort);
		addr.sin_addr.s_addr = htonl(INADDR_ANY);
		if(bind(iSocket, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
			cout<<"bind port " <<iPort<<"failed"<<strerror(errno)<<endl;
		}
		if(listen(iSocket, 300) == -1) {
			cout<<"listen failed "<<strerror(errno);
		}
	}

	int acceptSocket(int iListenSt) {
		struct sockaddr_in client_addr;
		socklen_t len = sizeof(client_addr);
		memset(&client_addr, 0, sizeof(client_addr));

		int client_st = accept(iListenSt, (struct sockaddr *) &client_addr, &len);
		if(client_st < 0) {
			cout<<"accept failed"<<strerror(errno);
		} else {
			cout<<"accept by" <<inet_ntoa(client_addr.sin_addr);
		}
		return client_st;	
	}

	void sendSocket(int st) {
		char s[] = "link success";
		send(st, s, strlen(s), 0);
	}

	void recvSocket(int ist, char *buffer) {
		char recvBuffer[MAXSIZE];
		memset(recvBuffer, 0, sizeof(recvBuffer));
		ssize_t rc = recv(ist, recvBuffer, sizeof(recvBuffer), 0);
		recvBuffer[MAXSIZE + 1] = '\0';
		cout<<"recv data rc NUM: " <<rc<<endl;
		if(rc <= 0) {
			cout<<"recv failed "<<strerror(errno)<<endl;
		} else {
			send(ist, recvBuffer, rc, 0);
		}
		cout<<recvBuffer<<endl;

		strcpy(buffer, recvBuffer);
	}

	int getst() {
		return iSocket;
	}

};
