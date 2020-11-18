#include "SLList.h"

SLList::SLList(int data) { m_data = data; }
const int SLList::getData() { return m_data; }
void SLList::setData(int data) { m_data = data; }
SLList* const SLList::next() { return m_nextElem; }
const bool SLList::hasNext() { return m_nextElem != nullptr; }

void SLList::removeNext() 
{ 
	m_nextElem->Delete();
	m_nextElem = nullptr; 
}

SLList* const SLList::beginList(int data)
{
	auto a = new SLList(data);
	a->first = true;
	return a;
}

SLList* const SLList::addElement(int data)
{
	if (hasNext()) return nullptr;
	else
	{
		auto a = new SLList(data);
		m_nextElem = a;
		return a;
	}
}

void SLList::Delete()
{
	if (first)
	{
		auto curr = m_nextElem;
		auto next = m_nextElem;
		while (next != nullptr)
		{
			curr = next;
			next = next->m_nextElem;
			delete curr;
		}
	}
	delete this;
}

void SLList::replaceNext(SLList* newNext)
{
	m_nextElem->Delete();
	m_nextElem = newNext;
}

void printSLList(const SLList* list)
{
	SLList s = *list;
	auto s2 = &s;
	while (s2 != nullptr)
	{
		cout << s2->getData() << endl;
		s2 = s2->next();
	}
}

//contains для map доступен только в с++20
bool containsMap(map<int, int>* m, int key)
{
	auto a = m->find(key);
	return a != m->end();
}

void distinctSLList(SLList* list)
{
	if (list->next() == nullptr) return;
	map <int, int> vals;
	SLList* prev = nullptr;
	SLList* curr = list;
	SLList* next = list->next();
	while (next != nullptr)
	{
		if (!containsMap(&vals, curr->getData())) vals.emplace(curr->getData(), 1);
		else
		{
			prev->replaceNext(next);
			curr = prev;
		}
		prev = curr;
		curr = next;
		next = next->next();
	}
	if (containsMap(&vals, curr->getData())) prev->removeNext();
}

SLList* findFromEnd(SLList* first, int index)
{
	SLList* curr = first->next();
	SLList* res = first;
	for (int i = 1; i < index; i++)
		curr = curr->next();
	while (curr != nullptr)
	{
		curr = curr->next();
		res = res->next();
	}
	return res;
}