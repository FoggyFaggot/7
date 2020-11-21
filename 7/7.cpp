#include <iostream>
#include "SLList.h"
#include <time.h>
#include <map>

using namespace std;

int main()
{
	srand(time(nullptr));
	auto a = SLList::beginList(rand() % 6);
	SLList* b = a;
	for (int i = 0; i < 9; i++)
	{
		b = b->addElement(rand() % 6);
	}
	printSLList(a);
	cout << "___________" << endl;
	distinctSLList(a);
	printSLList(a);
	cout << "___________" << endl;
	int q;
	cin >> q;
	cout << findFromEnd(a, q)->getData() << endl;
	cout << endl;
}