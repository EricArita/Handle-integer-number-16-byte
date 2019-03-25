#include "Qint.h"
#include "Helper.h"
#include "Task.h"

void Qint::setBitOfArrBit(int* arrBit, int bitIndex) {
	int arrIndex = bitIndex / 32;
	int index = bitIndex % 32;

	if (index > 0) {
		arrIndex = 3 - arrIndex;
		index--;
	}
	else {
		arrIndex = 4 - arrIndex;
		index = 31;
	}

	arrBit[arrIndex] = Bit::turnOnBit(arrBit[arrIndex], index);
}

Qint::Qint() {
	arrBit = new int[4]{ 0, 0, 0, 0 };
}

Qint::Qint(string numberString, int base) {
	arrBit = new int[4]{0, 0, 0, 0};
	int bitIndex = 1; //128 bits: from 1 to 128

	Hex_Bin['0'] = "0000";
	Hex_Bin['1'] = "0001";
	Hex_Bin['2'] = "0010";
	Hex_Bin['3'] = "0011";
	Hex_Bin['4'] = "0100";
	Hex_Bin['5'] = "0101";
	Hex_Bin['6'] = "0110";
	Hex_Bin['7'] = "0111";
	Hex_Bin['8'] = "1000";
	Hex_Bin['9'] = "1001";
	Hex_Bin['A'] = "1010";
	Hex_Bin['B'] = "1011";
	Hex_Bin['C'] = "1100";
	Hex_Bin['D'] = "1101";
	Hex_Bin['E'] = "1110";
	Hex_Bin['F'] = "1111";


	if (base == 2) {
		for (int i = numberString.size() - 1; i >= 0; i--) {
			if (numberString[i] == '1')
				setBitOfArrBit(arrBit, bitIndex);

			bitIndex++;
		}

		return;
	}

	if (base == 16) {
		for (int i = numberString.size() - 1; i >= 0; i--) {
			string binaryString = Hex_Bin[numberString[i]];
			
			for (int j = binaryString.size() - 1; j >= 0; j--) {
				if (binaryString[j] == '1')
					setBitOfArrBit(arrBit, bitIndex);

				bitIndex++;
			}
		}

		return;
	}

	if (base == 10) {
		string p = numberString;
		string q = "";
		int divisor = 2;
		bool isPossitiveNumber = true;

		if (p[0] == '-') {
			isPossitiveNumber = false;
			p.erase(0, 1);
		}

		while (p != "1")
		{
			int index = 0;
			int tmp = p[index] - '0';

			while (tmp < divisor)
				tmp = tmp * 10 + (p[++index] - '0');

			while (index < p.size())
			{
				q += (tmp / divisor) + '0';
				tmp = (tmp % divisor) * 10 + p[++index] - '0';
			}

			if ((p[p.size() - 1] - 48) % 2 != 0)
				setBitOfArrBit(arrBit, bitIndex);

			p = q;
			q = "";
			bitIndex++;
		}	

		setBitOfArrBit(arrBit, bitIndex);

		if (!isPossitiveNumber) {
			Qint tmp;
			tmp.setArrayBit(arrBit);
			tmp = Task::Add(Task::Not(tmp), Qint("1", 2));
			arrBit = tmp.getArrayBit();
		}

		return;
	}
}
