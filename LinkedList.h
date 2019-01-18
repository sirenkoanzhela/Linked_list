#pragma once
#include <iostream>
#include "Node.h"

typedef int DataType;

class LinkedList {
	Node*pHead;
	int count;
public:
	LinkedList() // default c'tor
	{
		pHead = nullptr;
	}

	LinkedList(int countNode, DataType _data)
	{
		if (countNode == 0)
		{
			pHead = nullptr;
			return;
		}
		if (countNode < 0)
		{
			return;
		}
		for (int i = 0; i < countNode; i++)
		{
			Node*pNew = new Node;
			pNew->setData(_data);
			pNew->setpNext(pHead);
			pHead = pNew;
			count++;
		}
	}
	LinkedList(const LinkedList&other)
	{
		count = other.count;
		for (int i = 0; i < count; i++)
		{
			Node*pNew = new Node;
			pNew->setData(other.pHead->getData());
			pNew->setpNext(pHead);
			pHead = pNew;
		}
	}
	~LinkedList()
	{
		for (int i = 0; i < count; i++)
		{
			Node*pDel = pHead;
			pHead = pHead->getpNext();
			delete pDel;
		}

	}
	LinkedList&operator = (const LinkedList&other)
	{
		if (this == &other) return *this;
		for (int i = 0; i < count; i++)
		{
			Node*pDel = pHead;
			pHead = pHead->getpNext();
			delete pDel;
		}
		count = other.count;
		for (int i = 0; i < count; i++)
		{
			Node*pNew = new Node;
			pNew->setData(other.pHead->getData());
			pNew->setpNext(pHead);
			pHead = pNew;
		}
	}
	void addToStart(DataType data = DataType())
	{
		Node*pNew = new Node;
		pNew->setData(data);
		pNew->setpNext(pHead);
		pHead = pNew;
	}
	void addToEnd(DataType data = DataType())
	{

	}
	void printList() //PRINT with WHILE
	{
		Node*pCurrent = pHead;
		while (pCurrent != nullptr)
		{
			std::cout << pCurrent->getData() << std::endl;
			pCurrent = pCurrent->getpNext();
		}
	}
	void printList_2() { //PRINT with FOR
		for (Node*pCurrent = pHead; pCurrent != nullptr; pCurrent = pCurrent->getpNext()) {
			std::cout << pCurrent->getData() << std::endl;
		}
	}
};