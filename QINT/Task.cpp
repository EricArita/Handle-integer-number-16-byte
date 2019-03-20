#include "Task.h"
#include <iostream>
using namespace std;

/*
	Status: Complete
*/
void Task::Convert_Qint_to_Binary(Qint num) {
	int* arrBit = num.getArrayBit();
	string res = "";

	for (int i = 3; i >= 0; i--) {
		for(int j = 1; j <= 32; j++)
		{
			char c = char(int(arrBit[i] & 1) + 48);
			res = c + res;
			arrBit[i] = arrBit[i] >> 1;
		}
	}

	while (res[0] == '0') res.erase(0, 1);

	cout << res << endl;
}

/*
	Status: Incomplete
*/
void Task::Convert_Qint_to_Hexadecimal(Qint num) {
}

/*
	Status: Incomplete
*/
void Task::Convert_Qint_to_Decimal(Qint num) {
}

/*
	Status: Incomplete
*/
Qint Task::Add(Qint numA, Qint numB) {
	return numA;
}

/*
	Status: Incomplete
*/
Qint Task::Subtract(Qint numA, Qint numB) {
	return numA;
}

/*
	Status: Incomplete
*/
Qint Task::Multiply(Qint numA, Qint numB) {
	return numA;
}

/*
	Status: Incomplete
*/
Qint Task::Divide(Qint numA, Qint numB) {
	return numA;
}

/*
	Status: Incomplete
*/
Qint Task::And(Qint numA, Qint numB) {
	return numA;
}

/*
	Status: Incomplete
*/
Qint Task::Or(Qint numA, Qint numB) {
	return numA;
}

/*
	Status: Incomplete
*/
Qint Task::Xor(Qint numA, Qint numB) {
	return numA;
}

/*
	Status: Incomplete
*/
Qint Task::SHL(Qint numA, int k) {
	return numA;
}

/*
	Status: Incomplete
*/
Qint Task::SHR(Qint numA, int k) {
	return numA;
}

/*
	Status: Complete
*/
Qint Task::Not(Qint num) {
	int* tmp = num.getArrayBit();
	for (int i = 3; i >= 0; i--)
		tmp[i] = ~tmp[i];
	num.setArrayBit(tmp);
	
	return num;
}

/*
	Status: Incomplete
*/
Qint Task::ROL(Qint num) {
	return num;
}

/*
	Status: Incomplete
*/
Qint Task::ROR(Qint num) {
	return num;
}
