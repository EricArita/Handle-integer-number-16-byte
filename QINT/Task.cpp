#include "Task.h"
#include "Helper.h"
#include <iostream>
using namespace std;

/*
	Status: Complete
*/
void Task::Convert_Qint_to_Binary(Qint num, bool secondOffsetNumberMode) {

	if (secondOffsetNumberMode) {
		num = Task::Not(num);
		Qint tmp("1", 2);
		num = Task::Add(num, tmp);
	}

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

	if (res.empty())
		cout << 0 << endl;
	else
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
	if (res.empty())
		res = "0";

	cout << res << endl;
}

/*
	Status: Complete
*/
void Task::Convert_Qint_to_Decimal(Qint num) {
	/*
		This method uses 'Binary to BCD Conversion algorithm' to convert binary to decimal
	*/

	int* arrBit = num.getArrayBit();
	bool bit = Bit::getBit(arrBit[0], 31);

	if (bit == 1)
		num = Task::Not(Task::Subtract(num, Qint("1", 2)));

	arrBit = num.getArrayBit();
	string bitString = "";

	for (int i = 3; i >= 0; i--)
		for (int j = 0; j < 32; j++)
			bitString = char(Bit::getBit(arrBit[i], j) + 48) + bitString;
	
	while (bitString[0] == '0') bitString.erase(0, 1);

	int res[50] = {0};

	while (!bitString.empty()) {
		for (int i = 0; i < 50; i++) {
			if (res[i] >= 5) {
				res[i] += 3;
			}
		}
		
		for (int i = 0; i < 50; i++) {
			res[i] = Bit::turnOffBit(res[i], 3) << 1;

			if (i == 49) {
				if (bitString[0] == '1')
					res[i] = Bit::turnOnBit(res[i], 0);
			}
			else {
				if (Bit::getBit(res[i+1], 3) == 1)
					res[i] = Bit::turnOnBit(res[i], 0);	
			}
		}
			
		bitString.erase(0, 1);
	}

	for (int i = 0; i < 50; i++)
		bitString += char(res[i] + 48);

	while (bitString[0] == '0') 
		bitString.erase(0, 1);

	if (bitString.empty()) {
		cout << 0 << endl;
		return;
	}

	if (bit == 1)
		bitString = '-' + bitString;
	
	cout << bitString << endl;
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
	Status: Complete
*/
Qint Task::Subtract(Qint numA, Qint numB) {
	Qint tmp("1", 2);
	numB = Task::Add(Task::Not(numB), tmp);
	
	return Task::Add(numA, numB);
}

/*
	Status: Complete
*/
Qint Task::Multiply(Qint numA, Qint numB) {
	/*
		This method uses Booth's Algorithm to multiply 2 binary numbers
	*/

	Qint tmp;
	bool bit = 0;
	int storeNumB[4];

	for (int i = 0; i < 4; i++)
		storeNumB[i] = numB.getArrayBit()[i];

	for (int i = 128; i > 0; i--) {		
		if (Bit::getBit(numA.getArrayBit()[3], 0) == 0) {
			if (bit == 1) {
				tmp = Task::Add(tmp, numB);

				for (int i = 0; i < 4; i++)
					numB.getArrayBit()[i] = storeNumB[i];
			}
		}
		else {
			if (bit == 0) {
				tmp = Task::Subtract(tmp, numB);

				for (int i = 0; i < 4; i++)
					numB.getArrayBit()[i] = storeNumB[i];
			}
		}

		bit = Bit::getBit(numA.getArrayBit()[3], 0);
		numA = Task::SHR(numA, 1);

		bool k = Bit::getBit(tmp.getArrayBit()[3], 0);	
		numA.getArrayBit()[0] = Bit::setBit(numA.getArrayBit()[0], 31, k);
		
		tmp = Task::SHR(tmp, 1);
	}

	return numA;
}

/*
	Status: Complete
*/
Qint Task::Divide(Qint numA, Qint numB) {
	bool isPositive = true;
	
	if (Bit::getBit(numA.getArrayBit()[0], 31) == 1) {
		isPositive = false;
		numA = Task::Add(Task::Not(numA), Qint("1", 2));
	}

	if (Bit::getBit(numB.getArrayBit()[0], 31) == 1) {
		isPositive = isPositive == true ? false : true;
		numB = Task::Add(Task::Not(numB), Qint("1", 2));
	}

	Qint remainder;
	bool bit = 0;
	int storeRemainder[4];
	int storeNumB[4];

	for (int i = 128; i > 0; i--) {		
		remainder = Task::SHL(remainder, 1);
		bool k = Bit::getBit(numA.getArrayBit()[0], 31);
		remainder.getArrayBit()[3] = Bit::setBit(remainder.getArrayBit()[3], 0, k);

		for (int i = 0; i < 4; i++) {
			storeRemainder[i] = remainder.getArrayBit()[i];
			storeNumB[i] = numB.getArrayBit()[i];
		}

		numA = Task::SHL(numA, 1);
	
		remainder = Task::Subtract(remainder, numB);

		for (int i = 0; i < 4; i++)
			numB.getArrayBit()[i] = storeNumB[i];

		if (Bit::getBit(remainder.getArrayBit()[0], 31) == 1) {
			numA.getArrayBit()[3] = Bit::setBit(numA.getArrayBit()[3], 0, 0);
			for (int i = 0; i < 4; i++)
				remainder.getArrayBit()[i] = storeRemainder[i];
		}
		else
			numA.getArrayBit()[3] = Bit::setBit(numA.getArrayBit()[3], 0, 1);
	}

	if (!isPositive) 
		numA = Task::Add(Task::Not(numA), Qint("1", 2));

	return numA;
}

/*
	Status: Complete
*/
Qint Task::And(Qint numA, Qint numB) {
	int* arrBit_A = numA.getArrayBit();
	int* arrBit_B = numB.getArrayBit();
	int* res = new int[4]{ 0, 0, 0, 0 };

	for (int i = 3; i >= 0; i--) {
		res[i] = arrBit_A[i] & arrBit_B[i];
	}

	numA.setArrayBit(res);
	return numA;
}

/*
	Status: Complete
*/
Qint Task::Or(Qint numA, Qint numB) {
	int* arrBit_A = numA.getArrayBit();
	int* arrBit_B = numB.getArrayBit();
	int* res = new int[4]{ 0, 0, 0, 0 };

	for (int i = 3; i >= 0; i--) {
		res[i] = arrBit_A[i] | arrBit_B[i];
	}

	numA.setArrayBit(res);
	return numA;
}

/*
	Status: Complete
*/
Qint Task::Xor(Qint numA, Qint numB) {
	int* arrBit_A = numA.getArrayBit();
	int* arrBit_B = numB.getArrayBit();
	int* res = new int[4]{ 0, 0, 0, 0 };

	for (int i = 3; i >= 0; i--) {
		res[i] = arrBit_A[i] ^ arrBit_B[i];
	}

	numA.setArrayBit(res);
	return numA;
}

/*
	Status: Complete
*/
Qint Task::SHL(Qint num, int k) {
	int* arrBit = num.getArrayBit();

	for (int i = 0; i <= 3; i++) {
		for (int j = 31; j >= 0; j--) {
			if (j - k >= 0) {
				arrBit[i] = Bit::setBit(arrBit[i], j, Bit::getBit(arrBit[i], j - k));
			}
			else {
				int bitIndex = k % 32 == 0 ? (j - k + 32 * (k / 32)) : (j - k + 32 * (k / 32 + 1));
				int arrIndex = i + (k / 32);
				arrIndex = (k % 32) > j ? arrIndex + 1 : arrIndex;

				if (arrIndex <= 3) {
					arrBit[i] = Bit::setBit(arrBit[i], j, Bit::getBit(arrBit[arrIndex], bitIndex));
				}
				else {
					arrBit[i] = Bit::setBit(arrBit[i], j, 0);
				}
			}
		}
	}

	num.setArrayBit(arrBit);
	return num;
}

/*
	Status: Complete
*/
Qint Task::SHR(Qint num, int k) {
	int* arrBit = num.getArrayBit();
	int highestBit = Bit::getBit(arrBit[0], 31);

	for (int i = 3; i >= 0; i--) {
		for (int j = 0; j <= 31; j++) {
			if (j + k <= 31) {
				arrBit[i] = Bit::setBit(arrBit[i], j, Bit::getBit(arrBit[i], j + k));
			}
			else {
				int bitIndex = k / 32 == 0 ? k + j - 32 : j + (k % 32);
				int arrIndex = i - (k / 32);
				arrIndex = (k % 32) > (31 - j) ? arrIndex - 1 : arrIndex;

				if (arrIndex >= 0) {
					arrBit[i] = Bit::setBit(arrBit[i], j, Bit::getBit(arrBit[arrIndex], bitIndex));
				}
				else {
					arrBit[i] = Bit::setBit(arrBit[i], j, 0);
				}
			}
		}
	}

	if (highestBit == 1) {
		int i = 0;
		int j = 31;
		while (k != 0)
		{
			if (j < 0) {
				j = 31;
				i++;
			}

			arrBit[i] = Bit::setBit(arrBit[i], j, 1);
			
			j--;
			k--;
		}
	}

	num.setArrayBit(arrBit);
	return num;
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
	Status: Complete
*/
Qint Task::ROL(Qint num) {
	bool bit = Bit::getBit(num.getArrayBit()[0], 31);
	num = Task::SHL(num, 1);
	num.getArrayBit()[3] = Bit::setBit(num.getArrayBit()[3], 0, bit);

	return num;
}

/*
	Status: Complete
*/
Qint Task::ROR(Qint num) {
	bool bit = Bit::getBit(num.getArrayBit()[3], 0);
	num = Task::SHR(num, 1);
	num.getArrayBit()[0] = Bit::setBit(num.getArrayBit()[0], 31, bit);

	return num;
}
