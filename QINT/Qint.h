#pragma once
#include <string>
#include <map>
using namespace std;

class Qint {
	private:
		int* arrBit; //Store value of a base by using an int array when converting this base to Qint type
		map<char, string> Hex_Bin;
	private:
		/*
			Parameter:
				bitIndex: index of bit of Qint object
			Results:
				Set value 1 to bit at bitIndex of Qint object
		*/
		void setBitOfArrBit(int* arrBit, int bitIndex);
	public:
		Qint();

		/*
			Parameter:
				A number string that you want to convert to Qint type. This one will be stored in arrBit property.
				base parameter is the base of this numberString
			Results:
				Create an instance of Qint class and store numberString into arrBit property
		*/
		Qint(string numberString, int base);

		string getHex_Bin(char c) { return Hex_Bin[c]; }

		int* getArrayBit() { return arrBit; };
		void setArrayBit(int* value) { arrBit = value; }
};
