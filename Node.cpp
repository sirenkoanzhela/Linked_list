#include "Node.h"
#include <iostream>

void Node::setData(const DataType& _data)
{
	data = _data;
}
DataType Node::getData() const
{
	return data;
}
void Node::setpNext(Node*_pNext)
{
	pNext = _pNext;
}
const Node*Node::getpNext() const
{
	return pNext;
}
Node*Node::getpNext()
{
	return pNext;
}
void addListHead(const DataType& data, Node*& pHead) {  //Добавление УЗЛА в НАЧАЛО списка
	Node*pNew = new Node;
	pNew->setData(data);
	pNew->setpNext(pHead);
	pHead = pNew;
	// более короткий вариант:
	// pHead = new Node(data, pHead);

}

void addList(const DataType& data, Node* pCurrent) //Добавление УЗЛА в СЕРЕДИНУ списка
{
	Node*pNew = new Node(data);
	pNew->setpNext(pCurrent->getpNext());
	pCurrent->setpNext(pNew);
	// более короткий вариант:
	// pCurrent->setpNext(new Node(data, pCurrent->getpNext()));

}

void delListHead(Node*&pHead) //Удаление УЗЛА из НАЧАЛА списка
{
	Node*pDel = pHead;
	pHead = pHead->getpNext();
	delete pDel;
}

void delList(Node* pPrevious)  //Удаление УЗЛА из СЕРЕДИНЫ списка
{
	Node*pDel = pPrevious->getpNext();
	pPrevious->setpNext(pDel->getpNext());
	delete pDel;
}

void printList(Node* pHead)
{
	for (auto pCurrent = pHead; pCurrent != nullptr; pCurrent = pCurrent->getpNext())
	{
		std::cout << pCurrent->getData() << std::endl;
	}
}