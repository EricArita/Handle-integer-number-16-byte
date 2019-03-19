// QINT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Application.h"
#include <iostream>
using namespace std;

int main()
{
	const char* inputFile = "input.txt";
	const char* outputFile = "output.txt";
	Application::getInstance()->Start(inputFile, outputFile);
}
