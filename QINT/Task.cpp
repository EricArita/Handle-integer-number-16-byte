#include "Task.h"
#include "Helper.h"
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
	Status: Complete
*/
void Task::Convert_Qint_to_Hexadecimal(Qint num) {
	int* arrBit = num.getArrayBit();
	string res = "";

	for (int i = 3; i >= 0; i--) {
		string tmp = "";

		for (int j = 1; j <= 32; j++) {
			tmp = char(int(arrBit[i] & 1) + 48) + tmp;
			arrBit[i] = arrBit[i] >> 1;

			if (j % 4 == 0) {
				bool find = false;

				for (char c = '0'; c <= '9'; c++) {
					if (tmp == num.getHex_Bin(c)) {
						res = c + res;
						tmp = "";
						find = true;
						break;
					}
				}

				if (find) continue;

				for (char c = 'A'; c <= 'F'; c++) {
					if (tmp == num.getHex_Bin(c)) {
						res = c + res;
						tmp = "";
						find = true;
						break;
					}
				}
			}
		}
	}

	while (res[0] == '0') res.erase(0, 1);
	cout << res << endl;
}

/*
	Status: Incomplete
*/
void Task::Convert_Qint_to_Decimal(Qint num) {
}

/*
	Status: Complete
*/
Qint Task::Add(Qint numA, Qint numB) {
	bool remember = 0;
	int* arrBit_A = numA.getArrayBit();
	int* arrBit_B = numB.getArrayBit();
	int* res = new int[4]{0, 0, 0, 0};

	for (int i = 3; i >= 0; i--) {
		for (int j = 0; j < 32; j++) {
			int bit = (arrBit_A[i] & 1) + (arrBit_B[i] & 1);
			
			arrBit_A[i] = arrBit_A[i] >> 1;
			arrBit_B[i] = arrBit_B[i] >> 1;

			if (remember) bit++;
			
			if (bit == 0) continue;

			if (bit == 1) {
				res[i] = Bit::turnOnBit(res[i], j);
				remember = 0;
			}
			else {
				if (bit == 2)
					remember = 1;
				else{
					res[i] = Bit::turnOnBit(res[i], j);
					remember = 1;
				}
			}
		}
	}

	numA.setArrayBit(res);
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
