#include "Application.h"
#include "Qint.h"
#include "Task.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Application* Application::instance = NULL;

Application* Application::getInstance() {
	if (instance == NULL) {
		instance = new Application();
	}
	
	return instance;
}

Qint Application::Processing_Calculate(Qint numA, Qint numB, string operatorType) {
	if (operatorType == "+")
		return Task::Add(numA, numB);

	if (operatorType == "-")
		return Task::Subtract(numA, numB);

	if (operatorType == "*")
		return Task::Multiply(numA, numB);

	if (operatorType == "/")
		return Task::Divide(numA, numB);

	if (operatorType == "&")
		return Task::And(numA, numB);

	if (operatorType == "|")
		return Task::Or(numA, numB);

	if (operatorType == "^")
		return Task::Xor(numA, numB);
}

Qint Application::Processing_Calculate(Qint num, string operatorType, int moveBit) {
	if (operatorType == "<<")
		return Task::SHL(num, moveBit);

	if (operatorType == ">>")
		return Task::SHR(num, moveBit);

	if (operatorType == "~")
		return Task::Not(num);

	if (operatorType == "rol")
		return Task::ROL(num);

	if (operatorType == "ror")
		return Task::ROR(num);
}

void Application::Processing_Convert(Qint num, int targetBase) {
	switch (targetBase)
	{
		case 2:
			Task::Convert_Qint_to_Binary(num);
			break;
		case 10:
			Task::Convert_Qint_to_Decimal(num);
			break;
		case 16:
			Task::Convert_Qint_to_Hexadecimal(num);
			break;
	}
}

void Application::Start(const char* inputFile, const char* outputFile) {
	FILE* f1;
	FILE* f2;
	freopen_s(&f1, inputFile , "r", stdin);
	freopen_s(&f2, outputFile, "w", stdout);

	int currBase = 0;

	while (cin >> currBase)
	{
		string data;
		getline(cin, data);

		while (data[0] == ' ') data.erase(0, 1);
		while (data[data.size() - 1] == ' ') data.erase(data[data.size() - 1], 1);

		bool done = false;
		for (int i = 0; i < 12; i++) {
			size_t found = data.find(Operators[i]);

			if (found != string::npos) {
				if (Operators[i] == "~" || Operators[i] == "rol" || Operators[i] == "ror") {
					if (Operators[i] == "~") {
						Qint num(data.substr(found + 2, data.size() - 2), currBase);
						Qint res = Processing_Calculate(num, Operators[i], 0);
						Processing_Convert(res, currBase);
					}
					else {
						Qint num(data.substr(found + 4, data.size() - 4), currBase);
						Qint res = Processing_Calculate(num, Operators[i], 0);
						Processing_Convert(res, currBase);
					}
				}
				else {
					if (Operators[i] == ">>" || Operators[i] == "<<") {
						Qint num(data.substr(0, found - 1), currBase);

						stringstream stream(data.substr(found + 3, data.size() - found - 3));
						int amountBit;
						stream >> amountBit;

						Qint res = Processing_Calculate(num, Operators[i], amountBit);
						Processing_Convert(res, currBase);
					}
					else {
						Qint numA(data.substr(0, found - 1), currBase);
						Qint numB(data.substr(found + 2, data.size() - found - 2), currBase);
						Qint res = Processing_Calculate(numA, numB, Operators[i]);
						Processing_Convert(res, currBase);
					}
				}

				done = true;
				break;
			}
		}

		if (done) continue;
						
		if (data[0] == '2') {
			Qint num(data.substr(2, data.size() - 2), currBase);
			Processing_Convert(num, 2);
		}
		else {
			if (data[1] == '6') {
				Qint num(data.substr(3, data.size() - 3), currBase);
				Processing_Convert(num, 16);
			}					
			else {
				Qint num(data.substr(3, data.size() - 3), currBase);
				Processing_Convert(num, 10);
			}					
		}						
	}
}