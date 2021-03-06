#include <iostream>
#include <stdlib.h>
#include "BinaryTree.h"
#include "Util.h"
using namespace std;

int main() {
	BinaryTree<int> tree(true);

	int addArray[] = { 20, 10, 30, 5 };
	//string addArray[] = { "hello", "hola", "bonjour", "teeth", "food", "dog" };

	for (auto addVal : addArray) {
 		if (ErrorCodes::FAILURE == tree.insertNode(addVal)) {
			return 1;
		}
	}

	/*
		iPrintType values:
		1 - in-order
		2 - pre-order
		3 - post-order
		4 - level-order
	*/
	for (int i = 1; i <= 4; i++) {
		tree.printTree(i);
		cout << endl;
	}

	tree.toggleAVL();

	for (int i = 1; i <= 4; i++) {
		tree.printTree(i);
		cout << endl;
	}

	cout << endl << "NUMBER OF NODES: " << tree.getSize() << endl;

	tree.deleteNode(119);
	//tree.deleteNode("hellO");

	for (int i = 1; i <= 4; i++) {
		tree.printTree(i);
		cout << endl;
	}

	cout << "Closest common ancestor: " << tree.findClosestCommonAncestor(112, 7) << endl;
	//cout << "Closest common ancestor: " << tree.findClosestCommonAncestor("hello", "hola") << endl;

	cout << endl << "NUMBER OF NODES: " << tree.getSize() << endl;

	return 0;
}