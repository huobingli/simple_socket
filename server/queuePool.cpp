#include "cacheLinkTable.cpp"
class queuePool {
private:
	cacheLinkTable *sendTable;
	cacheLinkTable *recvTable;

public:
	queuePool() {
		sendTable = new cacheLinkTable(10);
		recvTable = new cacheLinkTable(10);
	}

	~queuePool() {}

	cacheLinkTable *getSendTable() {
		return sendTable;
	}

	cacheLinkTable *getRecvTable() {
		return recvTable;
	}
};