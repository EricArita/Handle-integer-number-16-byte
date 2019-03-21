#pragma once
#include "Qint.h"

/*
	Class Task will contain all functions required by teacher
*/
class Task {
	public:
		static void Convert_Qint_to_Binary(Qint num,bool secondOffsetNumberMode);

		static void Convert_Qint_to_Decimal(Qint num);

		static void Convert_Qint_to_Hexadecimal(Qint num);
		//
		//Return result of (numA + numB) operations
		//
		static Qint Add(Qint numA, Qint numB);

		//
		//Return result of (numA - numB) operations
		//
		static Qint	Subtract(Qint numA, Qint numB);

		//
		//Return result of (numA * numB) operations
		//
		static Qint	Multiply(Qint numA, Qint numB);

		//
		//Return result of (numA / numB) operations
		//
		static Qint	Divide(Qint numA, Qint numB);

		//
		//Return result of (numA & numB) operations
		//
		static Qint	And(Qint numA, Qint numB);

		//
		//Return result of (numA | numB) operations
		//
		static Qint	Or(Qint numA, Qint numB);

		//
		//Return result of (numA ^ numB) operations
		//
		static Qint	Xor(Qint numA, Qint numB);

		//
		//Return result of (~ numA) operations
		//
		static Qint	Not(Qint num);

		//
		// Shift left k bit of num
		//
		static Qint SHL(Qint num, int k);

		//
		//Shift right k bit of num
		//
		static Qint SHR(Qint num, int k);

		//
		//Rotate left one bit
		//
		static Qint ROL(Qint num);

		//
		//Rotate right one bit
		//
		static Qint ROR(Qint num);
	
};