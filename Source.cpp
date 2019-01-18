#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

int main()
{
	LinkedList l2(3,5);
	l2.addToStart(2);
	l2.printList();
	system("pause");
	return 0;
}