#include <iostream>
#include <string>


#include "messageBuffer.cpp"
#include "userBuffer.cpp"
#include "package.cpp"
using namespace std;

int main() {
	// messageBuffer *message = new messageBuffer();
	// messageBuffer *pmessage = new messageBuffer();
	// char operateBuffer[6] = "00000";
	// char messageBuffer[501] = "22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222";
	// message->setOperateFlag(1);
	// message->setOperateLength(5);
	// message->setMessageFlag(1);
	// message->setMessageLength(500);
	// message->setOperateBuffer(operateBuffer);
	// message->setMessageBuffer(messageBuffer);
	// message->toString();

	// char buffer[MAXSIZE];
	// memset(&buffer, 0, sizeof(buffer));
	// // message->getBuffer(buffer);
	// // cout<<"buffer"<<buffer<<endl;
	// // messageBuffer *pmessage = new messageBuffer();
	// message->copyBuffer(pmessage);
	// pmessage->getBuffer(buffer);
	// cout<<buffer<<endl;
	// cout<<"-----------------------------------------------------------"<<endl;
	// pmessage->messageDivide();
	// pmessage.
	//message->


	// char username[21] = "huobinglihuobingli11";
	// char password[21] = "12345678901234567890";
	// userBuffer *pUserBuffer = new userBuffer();
	// pUserBuffer->setUserNameBuffer(username);
	// //cout<<strlen("huobinglihuobingli11")<<endl;
	// pUserBuffer->setUserNameLength(20);
	// pUserBuffer->setPasswordBuffer(password);
	// //cout<<strlen("12345678901234567890")<<endl;
	// pUserBuffer->setPasswordLength(20);
	
	// //pUserBuffer->cout1();
	// pUserBuffer->toString();
	// cout<<endl;
	//pUserBuffer->divideMessage();


	messagePackage *temp = new messagePackage();
	temp->setOperateType("0111");
	temp->setMessageBuffer("321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321321");
	temp->toString();
	//temp->divideString();
	return 0;
}
