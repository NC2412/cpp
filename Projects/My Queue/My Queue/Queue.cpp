#include <limits>
#include "Queue.h"

Queue::Queue() {
	m_pHead = NULL;
	m_pTail = NULL;
}

Queue::~Queue() {
	deleteQueue();
}

template <typename T>
ErrorCodes Queue::enqueue(T value)
{
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;
	Node* newNode = new Node;
	newNode->value = value;

	if (NULL == m_pHead) {
		m_pHead = newNode;
		m_pTail = m_pHead;
	}
	else {
		m_pTail->pNext = newNode;
		m_pTail = m_pTail->pNext;
	}

	return ecRetCode;
}

//
// TODO 
// 
// How will i return a NULL value?
//
template <typename T>
T Queue::dequeue()
{
	int value = m_pHead->value;
	Node* temp = m_pHead;

	if (isEmpty()) {
		return INT_MIN;
	}

	m_pHead = m_pHead->pNext;
	temp->pNext = NULL;
	delete temp;

	return value;
}

ErrorCodes Queue::deleteQueue() {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	if (NULL == m_pHead)
		return ecRetCode;

	while (NULL != m_pHead) {
		Node<int>* tempNode = m_pHead;
		m_pHead = m_pHead->pNext;
		tempNode->pNext = NULL;
		delete tempNode;
	}

	return ecRetCode;
}