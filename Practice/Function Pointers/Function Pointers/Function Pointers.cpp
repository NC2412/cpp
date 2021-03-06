#include <iostream>
#include <vector>
using namespace std;

/*
	Functions can be called via pointers, just like variables.
	Function pointers are called a lot behind the scenes in c++.
*/

void test(int value) {
	cout << "Hello: " << value << endl;
}

bool match(string text) {
	return text.size() == 3;
}

int countStrings(vector<string>& texts, bool (*match)(string test)) {
	int count = 0;
	for (int i = 0; i < texts.size(); i++) {
		if (match(texts[i]))
			count++;
	}

	return count;
}

int main() {

	// test with () calls the code inside of the method.
	// The () basically dereferences the pointer.
	test(10);

	// test without () will return the address of the function;
	cout << test << endl;

	// When declaring a function pointer, enclose the name with (), including the *.
	// Be sure to include () after the name. This will be where parameters are placed.
	//		- The following () will just include the parameter type, no need for the name.
	// This declaration is a pointer to a void function that takes no parameters.
	void (*pTest)(int) = test;

	// You need the () wrapping the name and * again in order to dereference the function call, not the return value.
	// *pTest() would call the function and dereference the return value.
	(*pTest)(8);

	vector<string> texts;
	texts.push_back("one");
	texts.push_back("two");
	texts.push_back("three");

	// When passing a function pointer, you only need to pass the name of the function, without ().
	cout << countStrings(texts, match) << endl;

	return 0;
}