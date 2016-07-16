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
//#include "function.cpp"
using namespace std;


static void *test(void *arg) {
	int st = *(int *)arg;

	cout<<st<<endl;
	char message[10] = "123123123";
	char intArray[5];
	char buffer[MAXSIZE];
	char stArray[5];
	for(int i= 0 ; i < 4; i++) {
		memset(buffer, 0, sizeof(buffer));
		memset(intArray, 0, sizeof(intArray));
		memset(stArray, 0, sizeof(stArray));
		intToChar(i, intArray);
		intToChar(st, stArray);

		strcat(buffer, "4");
		//cout<<buffer<<endl;
		strcat(buffer, intArray);
		//cout<<buffer<<endl;
		//cout<<buffer<<endl;
		strcat(buffer, "013");
		strcat(buffer, message);
		strcat(buffer, stArray);
		strcat(buffer, "\0");

		cout<<buffer<<endl;
		cout<<strlen(buffer)<<endl;
		send(st, buffer, strlen(buffer), 0);
		sleep(1);
	}

	while(1){
		cout<<"fa song wan bi "<<endl;
		sleep(100);
	}
}


int main()
{

	clientSocket *clientsocket = new clientSocket(10000);

	clientsocket->createClientSocket();
	clientsocket->connectServer();

	int st =  clientsocket->getst();
	
	clientsocket->judgeFlag();

	pthread_t thrd1, thrd2, thrd3, thrd4, thrd5, thrd6, thrd7, thrd8, thrd9, thrd10;

	pthread_create(&thrd1, NULL, clientSocket::sendSocket, &st);
	pthread_create(&thrd2, NULL, clientSocket::recvSocket, &st);

	pthread_create(&thrd3, NULL, test, &st);
	//pthread_join(thrd1, NULL);
	pthread_join(thrd2, NULL);
	//pthread_detach(thrd1);

	delete clientsocket;	
	return 0;
}
