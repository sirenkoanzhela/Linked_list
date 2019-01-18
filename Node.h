#pragma once

typedef int DataType;

class Node 
{
	DataType data;
	Node*pNext;
public:
	Node(const DataType& _data = DataType(), Node*_pNext=nullptr) : data(_data), pNext(_pNext){}
	void setData(const DataType& _data);
	DataType getData() const;
	void setpNext(Node*_pNext);
	Node* getpNext();
	const Node* getpNext()const;
};

void addListHead(const DataType& data, Node*& pHead);
void addList(const DataType& data, Node* pCurrent);
void delListHead(Node*&pHead);
void delList(Node* pPrevious);
void printList(Node* pHead);