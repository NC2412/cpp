#pragma once
#include <iostream>
#include "Util.h"
using namespace std;

class BinaryTree
{
	struct Node {
		int value = -1;

		Node* pLeft = NULL;
		Node* pRight = NULL;
		//Node* pNext = NULL;
	};

public:
	// CTORs and DTORs
	BinaryTree();
	~BinaryTree();

	// Operating methods
	ErrorCodes insertNode(int value);
	ErrorCodes deleteNode(int delValue);
	ErrorCodes printTree(int iPrintType);
	bool hasValue(int value);

	// TODO
	// use delete node as recursive
	//		- use helper methods
	// 
	// closest common ancestor
	//	- given two nodes, what is their common parent?
	//
	// threading siblings
	//  - left right next

private:
	// Private helper methods
	ErrorCodes setToPredecessor(Node* rootNode, Node* pCur, Node* pPrev);
	ErrorCodes setToSuccessor(Node* rootNode, Node* pCur, Node* pPrev);
	ErrorCodes deleteGivenNode(Node* pDelNode, Node* pDelPrev, Node* pCur, Node* pPrev);

	// Private operating methods
	ErrorCodes printInOrder(Node* pNode);
	ErrorCodes printPreOrder(Node* pNode);
	ErrorCodes printPostOrder(Node* pNode);
	ErrorCodes printLevelOrder();
	ErrorCodes deleteTree(Node* pNode);

private:
	// Member variables
	Node* m_pHead;
};

