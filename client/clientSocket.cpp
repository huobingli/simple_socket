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


<<<<<<< HEAD
#include "package.cpp"
//#include "function.cpp"
=======
#include "messageBuffer.cpp"
>>>>>>> f3ef76891cf061ffd9580a42c15246e0b1fbcb6e
#include "param.h"

using namespace std;

//static connect flag
static int flag = 0;


class clientSocket {
private:
	//communication socket
	int iSocket;
	//communication port
	int iPort;
	//socket param;
	struct sockaddr_in addr;
	// judge is connected
	int iConnect;

public:
	clientSocket(int iport) {
		iSocket = 0;
		iPort = iport;
		memset(&addr, 0, sizeof(addr));
	}

	~clientSocket() {}

	void createClientSocket() {
		iSocket = socket(AF_INET, SOCK_STREAM, 0);
		int on = 1;

		if(setsockopt(iSocket, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1) {
			cout<<"setsockopt failed"<<strerror(errno)<<endl;
		}
		// cout<<"addr.sin_family"<<addr.sin_family<<endl;
		// cout<<"addr.sin_port"<<addr.sin_port<<endl;
		// cout<<"sin_addr.s_addr"<<addr.sin_addr.s_addr<<endl;
	}

	//connect server ,set addr  param
	void connectServer() {
		addr.sin_family = AF_INET;
		addr.sin_port = htons(iPort);
		addr.sin_addr.s_addr = inet_addr("127.0.0.1");

		//connect server ,and return connect flag
		iConnect = connect(iSocket, (struct sockaddr *) &addr, sizeof(addr));

		// cout<<"addr.sin_family"<<addr.sin_family<<endl;
		// cout<<"addr.sin_port"<<addr.sin_port<<endl;
		// cout<<"sin_addr.s_addr"<<addr.sin_addr.s_addr<<endl;
		if(iConnect == 0)
		{
			cout<<"connect successed to "<<inet_ntoa(addr.sin_addr)<<endl;
		} else if (iConnect == -1) {
			cout<<"connect failed "<<strerror(errno);
			close(iSocket);
		} else {
			close(iSocket);
		}
	}

	//judge connect flag ,if flag == 0 connect fail,if flag  == 1 connect success
	void judgeFlag() {
		if(addr.sin_family != 0 && iConnect == 0)
			flag = 1;
		else{
			flag = 0;
		}
	}


	//send buffer function
	static void *sendSocket(void *arg) {
		int st = *(int *)arg;
		char recvBuffer[MAXSIZE];

		//messageBuffer *buffer = new messageBuffer();
		while(1) {
			if(flag == 0)
				break;
			memset(recvBuffer, 0, sizeof(recvBuffer));
			read(STDIN_FILENO, recvBuffer, sizeof(recvBuffer));
			//cout<<sizeof(recvBuffer)<<endl;

			//cout<<strlen(recvBuffer)<<endl;
			//recvBuffer[strlen(recvBuffer) - 1] = '\0';
			strcat(recvBuffer, "\0");
			//cout<<strlen(recvBuffer)<<endl;
			//buffer->setBuffer(recvBuffer);

			send(st, recvBuffer, strlen(recvBuffer), 0);
		}
	}

	//recv buffer function
	static void *recvSocket(void *arg) {
		int st = *(int *)arg;
		char recvBuffer[MAXSIZE];
		while(1) {
			if(flag == 0)
				break;
			memset(recvBuffer, 0, sizeof(recvBuffer));
			int rc = recv(st, recvBuffer, sizeof(recvBuffer), 0);
			if(rc <= 0) {
				break;
			}
			cout<<"client recv data: "<<recvBuffer<<endl;
		}
	}

	//get socket, used by recv and send funciton
	int getst() {
		return iSocket;
	}
};
