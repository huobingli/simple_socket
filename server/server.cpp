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

// #include "serverSocket.cpp"
// #include "epoll.cpp"
<<<<<<< HEAD
//#include "serverAnalyze.cpp"
=======
// #include "serverAnalyze.cpp"
>>>>>>> f3ef76891cf061ffd9580a42c15246e0b1fbcb6e
#include "threadControl.cpp"

//#include "queuePool.cpp"


using namespace std;

// struct serverRecv {
// 	serverSocket *serverSt;
// 	epoll *serverEpoll;
// 	cacheLinkTable *pLinkTable;
// };

// struct serverSend {
// 	cacheLinkTable *pLinkTable;
// };

// struct serverAnal {
// 	cacheLinkTable *pSendTable;
// 	cacheLinkTable *pRecvTable;
// };
// define server struction
struct serverRecv recvOprate;
struct serverSend sendOprate;
struct serverAnal doubleOperate;

// pthread_mutex_t RecvMutex = PTHREAD_MUTEX_INITIALIZER;
// pthread_mutex_t SendMutex = PTHREAD_MUTEX_INITIALIZER;
void setNoBlocking(int st)
{
	int opts = fcntl(st, F_GETFL);
	if(opts <0)
	{
		cout<<"fcntl failed "<< strerror(errno);
	}

	opts = opts | O_NONBLOCK; // 或运算
	if(fcntl(st, F_SETFL, opts) < 0)
	{
		cout<<"fcntl failed "<< strerror(errno);
	}

	cout<<"set success"<<endl;
}


/*******************************************************************/
static void *epollRecv(void *arg) {

	cout<<"接受线程启动"<<endl;
	
	//canshu 	
	
	serverRecv *balabala = (struct serverRecv *) arg;
	serverSocket *serverSt = (*balabala).serverSt;
	epoll *serverEpoll = (*balabala).serverEpoll;
	cacheLinkTable *recvTable = (*balabala).pLinkTable;
	cout<<"epollRecv"<<endl;
	int listen_st = serverSt->getst();

	struct epoll_event ev;
	ev.data.fd = listen_st;

	ev.events = EPOLLIN | EPOLLERR | EPOLLHUP;

	serverEpoll->addEpoll(listen_st, ev);

	int st = 0;
	while(1) {
		int nfds = serverEpoll->waitEpoll(-1);
		cout<<"nfds : "<<nfds<<endl;
		if(nfds == -1) {
			cout<<"epoll wait failed"<<strerror(errno);
			break;
		}

		int i;
		int fd;

		for(i = 0; i<nfds; i++) {
			fd = serverEpoll->getfd(i);
			if(fd < 0) {
				continue;
			}

			if(fd == listen_st) {
				st = serverSt->acceptSocket(listen_st);
				cout<<"st = "<<st<<"; listen_st = "<<listen_st<<endl;
				
				if(st > 0) {
					setNoBlocking(st);
					ev.data.fd = st;
					ev.events = EPOLLIN | EPOLLERR | EPOLLHUP;
					serverEpoll->addEpoll(st, ev);
					continue;
				}				
			}


			__uint32_t events = serverEpoll->getEvent(i);
			st = serverEpoll->getfd(i);

			//socket get data
			if(events & EPOLLIN) {
				cout<<"recv from : " <<st<<endl;
				char buffer[MAXSIZE];
				memset(&buffer, 0, sizeof(buffer));
				serverSt->recvSocket(st, buffer);

				if(strlen(buffer) <= 0) {
					serverSt->sendSocket(st);
					close(st);
				} 
				if(strlen(buffer) > 0) {
					cout<<"recv buffer : "<<buffer <<endl;
					cacheLinkNode *cacheNode = new cacheLinkNode();
					cacheNode->setst(st);
					cacheNode->setbuffer(buffer);

					pthread_mutex_lock(&RecvMutex);
					cout<<"接收队列已经加锁，正在写入数据"<<endl;
					recvTable->insertNode(cacheNode);
					pthread_mutex_unlock(&RecvMutex);
					cout<<"接收队列已经解锁，等待中"<<endl;

					cout<<"end analyze recvTable Node NUM  "<<recvTable->getNodeNum()<<endl;
				}
			}
			//socket error
			if(events & EPOLLERR) {
				st = serverSt->acceptSocket(listen_st);
				close(st);
			}
			//socket unlinked
			if(events & EPOLLHUP) {
				st = serverSt->acceptSocket(listen_st);
				close(st);
			}
		}
	}
	
}
// /***********************************************************************/
// static void *epollSend(void *arg)
// {
// 	cout<<"发送线程启动"<<endl;
// 	struct serverAnal *balabala = (struct serverAnal*)arg;
// 	cacheLinkTable *psendTable = (*balabala).pSendTable;
	

// 	while(1){
// 		sleep(5);
// 		cout<<"send sendLinkTable Node NUM  "<<psendTable->getNodeNum()<<endl;
// 		//analyze->serverLinkTableAnalyze();
// 		//cout<<"end analyze sendLinkTable Node NUM  "<<sendLinkTable->getNodeNum()<<endl;
// 		//cout<<"end analyze recvLinkTable Node NUM  "<<recvLinkTable->getNodeNum()<<endl;
		
// 		//cout<<1111<<endl;
// 		if(psendTable->getNodeNum() > 0)
// 		{
			
// 			cout<<"有"<<psendTable->getNodeNum()<<"条要发送"<<endl;

// 			//sleep(5);
// 			pthread_mutex_lock(&SendMutex);
// 			cout<<"发送队列已经加锁"<<endl;
// 			cacheLinkNode *tempNode = psendTable->getEndNode();
// 			pthread_mutex_unlock(&SendMutex);
// 			cout<<"发送队列已经解锁"<<endl;

// 			int st = tempNode->getst();
// 			char *haha="服务器准备发送\t";
// 			send(st, haha, strlen(haha), 0);
// 			char buffer[MAXSIZE];
// 			memset(&buffer, 0, MAXSIZE);

// 			tempNode->getbuffer(buffer);
// 			//cout<<buffer<<endl;
// 			send(st, buffer, strlen(buffer), 0);

// 			cout<<"已经向"<<st<<"发送了"<<buffer<<endl;
// 		}
// 	}	
// }

// /***********************************************************************/
// static void *epollAnalyze(void *arg) {
// 	cout<<"处理线程启动"<<endl;
// 	struct serverAnal *balabala = (struct serverAnal *)arg;
// 	cacheLinkTable *sendTable = (*balabala).pSendTable;
// 	cacheLinkTable *recvTable = (*balabala).pRecvTable;
	
// 	char buffer[MAXSIZE];
// 	memset(&buffer, 0, sizeof(buffer));
// 	serverAnalyze *pServerAnalyze = new serverAnalyze();
// 	while(1){
// 		//cout<<"epoll analyze sendLinkTable Node NUM  "<<sendTable->getNodeNum()<<endl;
// 		cout<<"epoll analyze recvLinkTable Node NUM  "<<recvTable->getNodeNum()<<endl;
// 		sleep(10);
// 		if(recvTable->getNodeNum() != 0) {

// 			pthread_mutex_lock(&RecvMutex);
// 			cout<<"正在处理一条信息"<<endl;
// 			cacheLinkNode *tempLinkNode = recvTable->getEndNode();

// 			//messageBuffer *message = new messageBuffer();
			
// 			tempLinkNode->getbuffer(buffer);
// 			//set buffer
// 			pServerAnalyze->setBuffer(buffer);
// 			pServerAnalyze->judgeBuffer();
// 			//message->setBuffer(buffer);
// 			//message->messageDivide();

// 			//------------------------------
// 			//cacheLinkNode *insertSendTableNode = new cacheLinkNode();

// 			cout<<"dengdai "<<endl;
// 			sleep(5);
// 			//tempLinkNode->copyLinkNode(insertSendTableNode);

// 			pthread_mutex_unlock(&RecvMutex);
// 			cout<<"信息处理完毕"<<endl;
// 			//break;

// 			pthread_mutex_lock(&SendMutex);
// 			//cout<<"正在加入发送队列"<<endl;
// 			//sendTable->insertNode(insertSendTableNode);
// 			pthread_mutex_unlock(&SendMutex);
// 			cout<<"添加完成"<<endl;

// 			memset(&buffer, 0, sizeof(buffer));
// 		}

// 		sleep(5);
// 		//cout<<"epoll analyze end analyze sendLinkTable Node NUM  "<<sendTable->getNodeNum()<<endl;
// 		//cout<<"epoll analyze end analyze recvLinkTable Node NUM  "<<recvTable->getNodeNum()<<endl;
// 	}
// 	cout<<"处理线程退出"<<endl;
// }
/***********************************************************************/

int main () {
	// new send recv queue
	queuePool * pQueuePool = new queuePool();

	// init server listen socket
	
	recvOprate.serverSt = new serverSocket(10000);
	recvOprate.serverSt->createServerSocket();

	int listen_st = recvOprate.serverSt->getst();
	if(listen_st == 0)
		return 0;
	setNoBlocking(listen_st);

	// init epoll
	recvOprate.serverEpoll = new epoll(100);
	recvOprate.serverEpoll->createEpoll();

	//recv queue and send queue
	recvOprate.pLinkTable = pQueuePool->getRecvTable();
	sendOprate.pLinkTable = pQueuePool->getSendTable();
	doubleOperate.pRecvTable = recvOprate.pLinkTable;
	doubleOperate.pSendTable = sendOprate.pLinkTable;

	pthread_t thrd1, thrd2, thrd3, thrd4;
	pthread_create(&thrd1, NULL, epollRecv, &recvOprate);
	// pthread_create(&thrd3, NULL, epollAnalyze, &doubleOperate);
	// pthread_create(&thrd2, NULL, epollSend, &sendOprate);
	
	threadControl *pthreadControl = new threadControl(3,sendOprate.pLinkTable, recvOprate.pLinkTable);
	classpoint *threadPool = (struct classpoint *)malloc(sizeof(classpoint))	;
	threadPool->pThreadPool = pthreadControl->getThreadPool();
	pthread_t thrdHeart;
	pthread_create(&thrdHeart, NULL, threadControl::heartBreath, threadPool);

while(1) {}
	return 0;
}
