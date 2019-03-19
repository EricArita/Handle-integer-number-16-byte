#pragma once
#include "Qint.h"

/*
	Class Task will contain all functions required by teacher
*/
class Task {
	public:
		static void Convert_Qint_to_Binary(Qint num) {};

		static void Convert_Qint_to_Decimal(Qint num) {};

		static void Convert_Qint_to_Hexadecimal(Qint num) {};

		//
		//Return result of (numA + numB) operations
		//
		static Qint Add(Qint numA, Qint numB) { return numA; };

		//
		//Return result of (numA - numB) operations
		//
		static Qint	Subtract(Qint numA, Qint numB) { return numA; };

		//
		//Return result of (numA * numB) operations
		//
		static Qint	Multiply(Qint numA, Qint numB) { return numA; };

		//
		//Return result of (numA / numB) operations
		//
		static Qint	Divide(Qint numA, Qint numB) { return numA; };

		//
		//Return result of (numA & numB) operations
		//
		static Qint	And(Qint numA, Qint numB) { return numA; };

		//
		//Return result of (numA | numB) operations
		//
		static Qint	Or(Qint numA, Qint numB) { return numA; };

		//
		//Return result of (numA ^ numB) operations
		//
		static Qint	Xor(Qint numA, Qint numB) { return numA; };

		//
		//Return result of (~ numA) operations
		//
		static Qint	Not(Qint num) { return num; };

		//
		// Shift left k bit of num
		//
		static Qint SHL(Qint num, int k) { return num; };

		//
		//Shift right k bit of num
		//
		static Qint SHR(Qint num, int k) { return num; };

		//
		//Rotate left one bit
		//
		static Qint ROL(Qint num) { return num; };

		//
		//Rotate right one bit
		//
		static Qint ROR(Qint num) { return num; };
};