#include <iostream>
#include <cmath>

#include "function.cpp"

#define Login 001;
#define Check 010;
#define Resig 011;
#define Exits 100;


//sizeof(BYTE)  == 1
typedef unsigned char BYTE;


class messagePackage{
private:
	//1
	int  operateLength;
	char operateType[5];
	//3
	int messageLength;
	char messageBuffer[505];
	int packageLength;
	char package[512];
public:
	messagePackage() {
		operateLength = 0;
		messageLength = 0;
		packageLength = 0;
		memset(&operateType, 0, sizeof(operateType));
		memset(&messageBuffer, 0, sizeof(messageBuffer));
		memset(&package, 0,  sizeof(package));
	}
	~messagePackage() {

	}

	void setOperateType(char *pOperateType) {
		memcpy(operateType, pOperateType, strlen(pOperateType));
		operateLength = strlen(operateType);
		strcat(operateType, "\0");
	}

	void getOperateType(char *pOperateType) {
		memcpy(pOperateType, operateType, strlen(operateType));
		strcat(pOperateType, "\0");
	}

	int getOperateLength() {
		return operateLength;
	}

	void setMessageBuffer(char *pMessageBuffer) {
		memcpy(messageBuffer, pMessageBuffer, strlen(pMessageBuffer));
		messageLength = strlen(messageBuffer);
		strcat(messageBuffer, "\0");
	}

	void getMessageBuffer(char *pMessageBuffer) {
		memcpy(pMessageBuffer, messageBuffer, strlen(messageBuffer));
		strcat(pMessageBuffer, "\0");
	}

	int getMessageLength() {
		return messageLength;
	}

	int getPackageLength() {
		return packageLength;
	}

	//IntToChar(char *changeBuffer, int changeInt)
	void toString() {
		char pOperateLength[2];
		IntToChar(pOperateLength, operateLength);
		strcat(package, pOperateLength);
		strcat(package, operateType);
		char pMessageLength[4];
		IntToChar(pMessageLength, messageLength);
		strcat(package, pMessageLength);
		strcat(package, messageBuffer);
		strcat(package, "\0");
		packageLength = strlen(package);
		cout<<operateLength<<endl;
		cout<<messageLength<<endl;
		cout<<package<<endl;
		cout<<packageLength<<endl;
	}

	void setPackage(char *buffer) {
		memcpy(package, buffer ,strlen(buffer));
		strcat(package, "\0");
	}

	void divideString() {
		cout<<"---------------------------------------------"<<endl;
		char pOperateLength[2];
		divide(pOperateLength, package, 1, 1);
		operateLength = charToInt(pOperateLength);
		cout<<operateLength<<endl;

		divide(operateType, package, 2, operateLength);
		strcat(operateType, "\0");
		cout<<operateType<<endl;

		char pMessageLength[4];
		divide(pMessageLength, package, 2 + operateLength, 3);
		messageLength = charToInt(pMessageLength);
		cout<<messageLength<<endl;

		divide(messageBuffer, package, 2 + operateLength + 3, messageLength);
		strcat(messageBuffer, "\0");
		cout<<messageBuffer<<endl;
	}
};