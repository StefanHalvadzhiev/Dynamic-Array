#include <iostream>
#include "DynamicArray.h"
using namespace std;

int main() {
	DynamicArray<float> newArray(2);
	newArray.erase(2);

	for (unsigned int i = 0; i < newArray.getSize(); i++)
		cout << newArray[i] << endl;

	return 0;
}