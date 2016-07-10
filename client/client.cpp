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
#include <pthread.h>

#include "clientSocket.cpp"
using namespace std;



int main()
{

	clientSocket *clientsocket = new clientSocket(10000);

	clientsocket->createClientSocket();
	clientsocket->connectServer();

	int st =  clientsocket->getst();
	
	clientsocket->judgeFlag();

	pthread_t thrd1, thrd2;

	pthread_create(&thrd1, NULL, clientSocket::sendSocket, &st);
	pthread_create(&thrd2, NULL, clientSocket::recvSocket, &st);

	//pthread_join(thrd1, NULL);
	pthread_join(thrd2, NULL);
	//pthread_detach(thrd1);

	delete clientsocket;	
	return 0;
}
