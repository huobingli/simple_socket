#include <iostream>
#include <string.h>


#ifndef PARAM
#define PARAM
	#include "param.h"
#endif
//#include "param.h"

using namespace std;

class cacheLinkNode {
private:
	int st;
	char NodeBuffer[MAXSIZE];
	cacheLinkNode *nextNode;
	cacheLinkNode *priorNode;
public:
	cacheLinkNode() {
		st = 0;
		memset(&NodeBuffer, 0, sizeof(NodeBuffer));
		nextNode = NULL;
		priorNode = NULL;
	}

	~cacheLinkNode() {}

	void setst(int socket) {
		st = socket;
	}

	int getst() {
		return st;
	}

	void setbuffer(char* buffer) {
		memcpy(NodeBuffer, buffer, strlen(buffer));
		strcat(NodeBuffer, "\0");
	}

	void getbuffer(char *buffer) {
		memcpy(buffer, NodeBuffer, strlen(NodeBuffer));
		strcat(buffer, "\0");
	}

	cacheLinkNode *getNextNode() {
		return nextNode;
	}
	cacheLinkNode *getPriorNode() {
		return priorNode;
	}

	void setNextNode(cacheLinkNode * nextnode) {
		nextNode = nextnode;
	}
	void setPriorNode(cacheLinkNode *priornode) {
		priorNode = priornode;
	}

	//node' prior and next point need init NULL,then copy
	void copyLinkNode(cacheLinkNode *pLinkNode) {
		if(pLinkNode->getPriorNode() == NULL && pLinkNode->getNextNode() == NULL) {
			//set buffer 
			pLinkNode->setbuffer(NodeBuffer);
			//set st
			pLinkNode->setst(st);
		}
	}

};


class cacheLinkTable {
private:
	cacheLinkNode *headNode;
	int iNodeNum;
	int iTotalNum;
	cacheLinkNode *endNode;
public:	
	cacheLinkTable(int iNum) {
		iTotalNum = iNum;
		iNodeNum = 0;
		headNode = NULL;
		endNode = NULL;
	}

	~cacheLinkTable() {}

	//tou cha fa
	void insertNode(cacheLinkNode *insertNode) {
		if(iNodeNum != iTotalNum) {
			if(headNode == NULL){
				headNode = insertNode;
				endNode = insertNode;
				
			} else {
				cacheLinkNode *pTempNode = headNode;
				//insert node
				headNode = insertNode;
				insertNode->setNextNode(pTempNode);
				pTempNode->setPriorNode(insertNode);
			}
			iNodeNum++;
		}
	}

	bool AnalyzeNode() {
		if(iNodeNum == 0){
			return false;
		} else {
			getEndNode();
			return true;
		}
	}

	// cacheLinkNode *getEndNode() {
	// 	return endNode;
	// }

	cacheLinkNode *getEndNode() {
		if(iNodeNum > 1) {
			cacheLinkNode *tempEndNode = endNode;
			endNode = endNode->getPriorNode();
			endNode->setNextNode(NULL);
			tempEndNode->setPriorNode(NULL);
			iNodeNum--;
			return tempEndNode;
		} else if(iNodeNum = 0) {
			return NULL;
		} else if(iNodeNum = 1) {
			cacheLinkNode *tempEndNode = endNode;
			endNode = NULL;
			headNode = NULL;
			iNodeNum--;
			return tempEndNode;
		}
	}

	int getNodeNum() {
		return iNodeNum;
	}

};


