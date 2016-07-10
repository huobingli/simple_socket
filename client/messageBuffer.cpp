#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cmath>
using namespace std;
#define MAXSIZE 512


void divide(char * dest,char * src,int start,int n)
{
	src=src+start-1;
	while ( (* dest++ = * src++) && n-1)
		n--;
	* dest='\0';
}

class messageBuffer{
private:
	//1
	int operateFlag;
	//5
	char operateBuffers[5];
	//1
	int operateLength;
	//1
	int messageFlag;
	//500
	char messageBuffers[501];
	//3
	int messageLength;
	//transport buffer
	char buffer[MAXSIZE];
public:
	messageBuffer() {
		operateFlag = 0;
		operateLength = 0;
		messageFlag = 0;
		messageLength = 0;
		// cout<<strlen(operateBuffers)<<endl;
		// cout<<strlen(messageBuffers)<<endl;
		// cout<<sizeof(operateBuffers)<<endl;
		// cout<<sizeof(messageBuffers)<<endl;
		memset(&operateBuffers, 0, sizeof(operateBuffers));
		memset(&messageBuffers, 0, sizeof(messageBuffers));
		memset(&buffer, 0, sizeof(buffer));
	}
	~messageBuffer() {	}
	void setOperateFlag(int flag) {
		operateFlag = flag;
	}
	int getOperateFlag() {
		return operateFlag;
	}
	void setMessageFlag(int flag) {
		messageFlag = flag;
	}
	int getMessageFlag() {
		return messageFlag;
	}
	void setOperateBuffer(char *buffer) {
		cout<<"buffer "<<strlen(buffer)<<endl;
		memcpy(operateBuffers, buffer, strlen(buffer));
		strcat(operateBuffers, "\0");
	}
	void getOperateBuffer(char *buffer) {
		memcpy(buffer, operateBuffers, strlen(operateBuffers));
		strcat(buffer, "\0");
	}
	void setMessageBuffer(char *buffer) {
		cout<<"buffer "<<strlen(buffer)<<endl;
		memcpy(messageBuffers, buffer, strlen(buffer));
		strcat(messageBuffers, "\0");
	}
	void getMessageBuffer(char *buffer) {
		memcpy(buffer, messageBuffers, strlen(messageBuffers));
		strcat(buffer, "\0");
	}
	void setOperateLength(int length) {
		operateLength = length;
	}
	int getOperateLength() {
		return operateLength;
	}
	void setMessageLength(int length) {
		messageLength = length;
	}
	int getMessageLength() {
		return messageLength;
	}
	void getBuffer(char *pbuffer) {
		//cout<<strlen(pbuffer)<<endl;
		//cout<<strlen(buffer)<<endl;
		memcpy(pbuffer, buffer, strlen(buffer));
		strcat(pbuffer, "\0");
	}

	void setBuffer(char *pbuffer) {
		memcpy(buffer, pbuffer, strlen(pbuffer));
		strcat(buffer, "\0");
		cout<<"strlen(buffer) "<<strlen(buffer)<<endl;
		cout<<"strlen(pbuffer) "<<strlen(pbuffer)<<endl;
		cout<<buffer<<endl;
	}
	void  toString() {
		//char buffer[512];
		//memset(&buffer, 0, sizeof(buffer));

		//change operate flag 
		char pOperateFlag[1];
		//itoa(operateFlag, pOperateFlag, 10);
		sprintf(pOperateFlag, "%d", operateFlag);
		strcat(buffer, pOperateFlag);
		cout<<"operateFlag "<<buffer<<endl;

		//change operate length
		char pOperateLength[1];
		//itoa(operateLength, pOperateLength, 10);
		sprintf(pOperateLength, "%d", operateLength);
		strcat(buffer, pOperateLength);

		cout<<"operateLength "<<buffer<<endl;
		//operate buffer
		strcat(buffer, operateBuffers);
		cout<<"operateBuffers "<<buffer<<endl;

		//change message flag
		char pMessageFlag[1];
		//itoa(messageFlag, pMessageFlag, 10);
		sprintf(pMessageFlag, "%d", messageFlag);
		strcat(buffer, pMessageFlag);
		cout<<"messageFlag "<<buffer<<endl;
		//change message length
		char pMessageLength[3];
		//itoa(messageLength, pMessageLength, 10);
		sprintf(pMessageLength, "%d", messageLength);
		strcat(buffer, pMessageLength);
		cout<<"messageLength "<<buffer<<endl;
		//message buffer
		strcat(buffer, messageBuffers);
		//cout<<buffer<<endl;
		strcat(buffer, "\0");
		/*char endchar[1];
		divide(endchar, buffer, 512 ,1);
		cout<<endchar<<endl;
		cout<<"endchar "<<(endchar[1] == '\0')<<endl;
		cout<<(buffer[512] == '\0')<<endl;*/
		//cout<<"messageBuffers "<<buffer<<endl;
		cout<<"toString END"<<endl;
	}

	void messageDivide() {
		//cout<<buffer<<endl;
		//cout<<strlen(buffer)<<endl;
		char pOperateFlag[1];
		divide(pOperateFlag, buffer, 1, 1);
		//cout<<"operateFlag "<<pOperateFlag<<endl;
		operateFlag = (pOperateFlag[0] -'0');
		//cout<<operateFlag<<endl;

		char pOperateLength[1];
		divide(pOperateLength, buffer, 2, 1);
		//cout<<"operateLength "<<pOperateLength<<endl;
		operateLength = (pOperateLength[0] - '0');

		char pOperateBuffers[5];
		divide(pOperateBuffers, buffer, 3, 5);
		//cout<<"pOperateBuffers "<<pOperateBuffers<<endl;
		memcpy(operateBuffers, pOperateBuffers, strlen(pOperateBuffers));

		char pMessageFlag[1];
		divide(pMessageFlag, buffer, 8, 1);
		//cout<<"pMessageFlag "<<pMessageFlag<<endl;
		messageFlag = (pMessageFlag[0] - '0');
		//cout<<messageFlag<<endl;

		char pMessageLength[3];
		divide(pMessageLength, buffer, 9, 3);
		//cout<<"pMessageLength "<<pMessageLength<<endl;
		int length = strlen(pMessageLength);
		//cout<<length<<endl;
		int wei = 0;
		for(int i = 0; i < length; i++) {
			wei = (pMessageLength[i] - '0');
			messageLength = messageLength + pow(10, length - i -1) * wei;
			//cout<<pow(10, length - i) *wei<<endl;
		}
		//cout<<messageLength<<endl;

		char pMessageBuffers[500];
		divide(pMessageBuffers, buffer, 12, 500);
		//cout<<"pMessageBuffers "<<pMessageBuffers<<endl;
		memcpy(messageBuffers, pMessageBuffers, strlen(pMessageBuffers));
		//cout<<messageBuffers<<endl;

		/*char endchar[1];
		divide(endchar, buffer, 512, 1);
		cout<<endchar<<endl;
		cout<<(endchar[1] == '\0')<<endl;*/
		cout<<operateFlag<<endl;
		cout<<operateLength<<endl;
		cout<<operateBuffers<<endl;
		cout<<messageFlag<<endl;
		cout<<messageLength<<endl;
		cout<<messageBuffers<<endl;
	}


	void copyBuffer(messageBuffer *pmessageBuffer) {
		cout<<"copyBuffer START"<<endl;
		cout<<"pmessageBuffer "<<pmessageBuffer->buffer<<endl;

		cout<<"buffer "<<buffer<<endl;
		memcpy(pmessageBuffer->buffer, buffer ,strlen(buffer));
	}
};