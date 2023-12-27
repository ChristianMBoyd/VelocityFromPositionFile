#include <iostream>
#include "String.h"
#include "Decimal.h"
#include "Position.h"

void holdOutputWindow();

int main() {

	holdOutputWindow();
	return 0;
}

void holdOutputWindow() {
	String inputString;
	std::cout << "Enter anything to close.\n";
	std::cin >> inputString;
}