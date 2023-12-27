#include <iostream>
#include "String.h"

void holdOutputWindow();

int main() {
	std::cout << "Hello World!\n";

	holdOutputWindow();
	return 0;
}

void holdOutputWindow() {
	String inputString;
	std::cout << "Enter anything to close.\n";
	std::cin >> inputString;
}