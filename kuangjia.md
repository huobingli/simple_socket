### client
class clientSocket messageBuffer
clientSocket{
private:
	int iSocket;
	int iPort;
	struct sockaddr_in addr;
	int iConnect;
public:
	clientSocket(int iport);
	~clientSocket();
	void createClientSocket();
	void connectServer();
	void judgeFlag();
	static void *sendSocket(void *arg);
	static void *recvSocket(void *arg);
	int getst()
};
messageBuffer{
private:
	int operateFlag;
	char operateBuffer;
	int operateLength;
	int messageFlag;
	char messageFlag;
	int messageLength;
public:
	messageBuffer();
	~messageBuffer();
	void setOperateFlag(int flag);
	void setMessageFlag(int flag);
	void setOperateBuffer(char *buffer);
	void setMessageBuffer(char *buffer);
	void setOperateLength(int length);
	void setMessageLength(int length);
	void toString();
};

### server
class:
	serverSocket 
	epoll 
	cacheLinkTable
	analyzeMessage
serverSocket{
private:
	int iSocket;
	int iPort;
public:
	serverSocket(int iport);
	~serverSocket();
	void createServerSocket();
	int acceptSocket(int iListenSt);
	void sendSocket(int st);
	void recvSocekt(int st, char *buffer);
	int getst();
};
epoll{
private:
	int iMaxLink;
	int iEpfd;
	struct epoll_event *pEvents;
	int iLinkNum;
public:
	epoll(int num);
	~epoll();
	int createEpoll();
	int waitEpoll(int second);
	void addEpoll(int st, struct epoll_event ev)
	void deleteEpoll(int st, struct epoll_event ev);
	__uint32_t getEvent(int i);
	int getfd(int i);
};
cacheLinkNode{
private:
	int st;
	char NodeBuffer[MAXSIZE];
	cacheLinkNode *nextNode;
	cacheLinkNode *priorNode;
public:
	cacheLinkNode();
	~cacheLinkNode();
	void setst(int socket);
	int getst();
	void setbuffer(char* buffer);
	void getbuffer(char *buffer);
	cacheLinkNode *getNextNode();
	cacheLinkNode *getPriorNode();
	void setNextNode(cacheLinkNode *nextnode);
	void setPriorNode(cacheLinkNode *priornode);
	void copyLinkNode(cacheLinkNode *pLinkNode);
};
cacheLinkTable{
private:
	cacheLinkNode *headNode;
	cacheLinkNode *endNode;
	int iNodeNum;
	int iTotalNum;
public:
	cacheLinkTable(int num);
	~cacheLinkTable();
	void insertNode(cacheLinkNode *insertNode);
	bool AnalyzeNode();
	cacheLinkNode *getEndNode();
	int getNodeNum();
};

queuePool{
private:
	cacheLinkTable *sendTable;
	cacheLinkTable *recvTable;
public:
	queuePool();
	~queuePool();
	cacheLinkTable *getSendTable();
	cacheLinkTable *getRecvTable();
};


messageBuffer
operateFlag == 1  &&  messageFlag == 1
login
regis
check