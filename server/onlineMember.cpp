
//********************************************************
//
//       FileName:      onlineMember.cpp
//
//       Author:         
//       Description:    
//       Create:        2016-12-06 20:43:18
//       Last Modified: 2016-12-06 20:43:18
//********************************************************



#include <iostream>

using namespace std;

struct onlineArray{
  int st;
  bool isOnLine;
  bool isNeedSave;
};

#ifndef _ONLINEMEMBER_CPP
#define _ONLINEMEMBER_CPP
class onlineMember {
private:
  onlineArray *m_onLine;
  int m_onLineNum;
  int m_TotalNum;
private:
  bool empty() { return m_onLineNum == 0;}
  bool full() { return m_onLineNum == m_TotalNum; }
public:
  onlineMember(int iNum) {
    m_onLine = (struct onlineArray*)malloc(sizeof(onlineArray) * iNum);
    m_onLineNum = 0;
    m_TotalNum = iNum;
  }
  
  ~onlineMember() { free *m_onLine; }

  int getOnLineNum() { return m_onLineNum; }
  void insertArray(int iSt) {
    if(full()) { return; }
    else {
      m_onLine[m_onLineNum].st = iSt;
      m_onLine[m_onLineNum].isOnLine = true;
      m_onLine[m_onLineNum].isNeedSave = true;
    }
  }

  void clearArray() { 
    if(empty()) { return; }
    else { 
      
    }
  }
}

#endif

