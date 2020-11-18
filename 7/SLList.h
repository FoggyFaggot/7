#pragma once
#include <iostream>
#include <map>

using namespace std;

class SLList
{
	SLList* m_nextElem = nullptr;
	int m_data = 0;
	bool first = false;
	SLList(int data);
	
public:
	SLList() = delete;
	const int getData();
	void setData(int data);
	SLList* const next();
	const bool hasNext();
	static SLList* const beginList(int data);
	SLList* const addElement(int data);
	void removeNext();
	void Delete();
	void replaceNext(SLList* newNext);
};

void printSLList(const SLList* list);
void distinctSLList(SLList* list);
SLList* findFromEnd(SLList* first, int index);