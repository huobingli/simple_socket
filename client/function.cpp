#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
//int to binary 
//for port 16bit
void IntToBin(unsigned int dec,char ch[] ) {
      int i = 16;
      while(i >= 0)
      {
         int temp  = dec;
         temp = temp >> i;
         ch[17-i-1] = (temp & 1)+'0';
         i--;
      }
}

void CharToBin(char c) {
	unsigned char k = 0x80;
	for (int i=0; i<8; i++, k >>= 1)
	{
		if (c & k)
			cout<<"1";
		else
			cout<<"0";
	}
	cout<<" ";
}

void IntToChar(char *changeBuffer, int changeInt) {
	sprintf(changeBuffer, "%d", changeInt);
	strcat(changeBuffer, "\0");
}


void divide(char * dest,char * src,int start,int n)
{
	src=src+start-1;
	while ( (* dest++ = * src++) && n-1)
		n--;
	* dest='\0';
}