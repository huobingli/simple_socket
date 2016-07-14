#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define SIZE 21
#define BUFFERSIZE 50

// void divide(char * dest,char * src,int start,int n)
// {
// 	src=src+start-1;
// 	while ( (*dest++ = *src++) && n-1)
// 		n--;
// 	*dest='\0';
// }

class userBuffer{
private:
	//2
	int userNameLength;
	//20
	char userNameBuffer[SIZE];
	//2
	int passwordLength;
	//20
	char passwordBuffer[SIZE];
	char pbuffer[BUFFERSIZE];
public:
	userBuffer() {
		userNameLength = 0;
		memset(userNameBuffer, 0, sizeof(userNameBuffer));
		passwordLength = 0;
		memset(passwordBuffer, 0, sizeof(passwordBuffer));
		memset(pbuffer, 0, sizeof(pbuffer));
	}
	~userBuffer() {}

	void setUserNameLength(int length) {
		userNameLength = length;
	}

	int getUserNameLength() {
		return userNameLength;
	}
	void setPasswordLength(int length) {
		passwordLength = length;
	}

	int getPasswordLength() {
		return passwordLength;
	}

	void setUserNameBuffer(char *buffer) {

		memcpy(userNameBuffer, buffer, strlen(buffer));
		//strcat(userNameBuffer, "\0");
	}

	void getUserNameBuffer(char *buffer) {
		memcpy(buffer, userNameBuffer, strlen(userNameBuffer));
		strcat(buffer, "\0");
	}

	void setPasswordBuffer(char *buffer) {
		memcpy(passwordBuffer, buffer, strlen(buffer));
		//strcat(passwordBuffer, "\0");
	}

	void getPasswordBuffer(char *buffer) {
		memcpy(buffer, passwordBuffer, strlen(passwordBuffer));
		strcat(buffer, "\0");
	}

	void cout1() {
		cout<<"cout begin"<<endl;
		cout<<userNameLength<<endl;
		cout<<sizeof(userNameLength)<<endl;
		cout<<userNameBuffer<<endl;
		cout<<strlen(userNameBuffer)<<endl;
		cout<<passwordLength<<endl;
		cout<<sizeof(passwordLength)<<endl;
		cout<<passwordBuffer<<endl;
		cout<<strlen(passwordBuffer)<<endl;
		cout<<pbuffer<<endl;	
		cout<<"cout end"<<endl;
	}

	void toString() {
		cout<<"begin toString"<<endl;
		
		cout<<pbuffer<<endl;
		cout<<passwordBuffer<<endl;
		cout<<strlen(passwordBuffer)<<endl;
		
		char pUserNameLength[2];
		sprintf(pUserNameLength, "%d", userNameLength);
		strcat(pbuffer, pUserNameLength);
		cout<<"userNameLength "<<pbuffer<<"  strlen  "<<strlen(pbuffer)<<endl;

		cout<<passwordBuffer<<endl;
		cout<<strlen(passwordBuffer)<<endl;

		strcat(pbuffer, userNameBuffer);
		cout<<"userNameBuffer "<<pbuffer<<"  strlen  "<<strlen(pbuffer)<<endl;		

		cout<<passwordBuffer<<endl;
		cout<<strlen(passwordBuffer)<<endl;

		char pPasswordLength[2];
		sprintf(pPasswordLength, "%d", passwordLength);
		strcat(pbuffer, pPasswordLength);
		cout<<"passwordLength "<<pbuffer<<"  strlen  "<<strlen(pbuffer)<<endl;

		strcat(pbuffer, passwordBuffer);
		cout<<"passwordBuffer "<<pbuffer<<"  strlen  "<<strlen(pbuffer)<<endl;
	}

	// void divideMessage() {
	// 	char pUserNameLength[2];
	// 	divide(pUserNameLength, pbuffer, 0, 2);

	// 	int iUserNameLength = strlen(pUserNameLength);
	// 	for(int i = 0; i < iUserNameLength; i++) {
	// 		userNameLength = userNameLength + (pUserNameLength[i] - '\0') * pow(10, iUserNameLength - i -1);
	// 	}
	// 	cout<<userNameLength<<endl;
	// 	cout<<pUserNameLength<<endl;

	// 	divide(userNameBuffer, pbuffer , 2, 20);
	// 	cout<<userNameBuffer<<endl;

	// 	char pPasswordLength[2];
	// 	divide(pPasswordLength, pbuffer, 22, 2);
	// 	int iPasswordLength = strlen(pPasswordLength);
	// 	for(int i = 0; i < iPasswordLength; i++) {
	// 		passwordLength = passwordLength + (pPasswordLength[i] - '\0') * pow(10, iPasswordLength - i -1);
	// 	}
	// 	cout<<passwordLength<<endl;

	// 	divide(passwordBuffer, pbuffer, 24, 20);
	// 	cout<<passwordBuffer<<endl;
	// }
};