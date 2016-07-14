#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

	
void divide(char * dest,char * src,int start,int n)
{
	src=src+start-1;
	while ( (* dest++ = * src++) && n-1)
		n--;
	* dest='\0';
}

int main() {
	char buffer[10] = "123456789";
	
	cout<<buffer<<endl;

	char pbuffer[10];
	
	strncpy(pbuffer, buffer, 3, 5);
	cout<<strlen(pbuffer)<<endl;
	cout<<(pbuffer[4] == '\0')<<endl;
	cout<<pbuffer<<endl;
