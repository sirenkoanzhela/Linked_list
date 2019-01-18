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
void addListHead(const DataType& data, Node*& pHead) {  //���������� ���� � ������ ������
	Node*pNew = new Node;
	pNew->setData(data);
	pNew->setpNext(pHead);
	pHead = pNew;
	// ����� �������� �������:
	// pHead = new Node(data, pHead);

}

void addList(const DataType& data, Node* pCurrent) //���������� ���� � �������� ������
{
	Node*pNew = new Node(data);
	pNew->setpNext(pCurrent->getpNext());
	pCurrent->setpNext(pNew);
	// ����� �������� �������:
	// pCurrent->setpNext(new Node(data, pCurrent->getpNext()));

}

void delListHead(Node*&pHead) //�������� ���� �� ������ ������
{
	Node*pDel = pHead;
	pHead = pHead->getpNext();
	delete pDel;
}

void delList(Node* pPrevious)  //�������� ���� �� �������� ������
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