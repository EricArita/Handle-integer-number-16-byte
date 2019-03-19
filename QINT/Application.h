#pragma once
#include "Qint.h"
#include <string>
using namespace std;

class Application {
	private:
		const string Operators[12]{"+", "-", "*" , "/", "&", "|", "^", "~", "rol", "ror", "<<", ">>"};
		static Application* instance;

		Application() {};

		/*
			Parameter:
				Two operands(numA, numB) with operator(+, -, *, /, and, or, xor) to calculate.
			Results:
				Return an variable of Qint type that is resulted from calculation between numA and numB.
		*/
		Qint Processing_Calculate(Qint numA, Qint numB, string operatorType);

		/*
			Parameter:
					One operand(num) with operator(>>, <<, ~, rol, ror) to calculate.
					moveBit parameter is an amount of bits that 2 operators(>>, <<) use to move.
					If you only want to use "NOT ~" or "rol" or "ror" operator, you have to assign value 0 to moveBit.
			Results:
					Return an variable of Qint type that is resulted from calculation on num parameter.
		*/
		Qint Processing_Calculate(Qint num, string operatorType, int moveBit);

		/*
			Parameter:
				A number of Qint type and targetBase is the base to which you want to convert num
			Results:
				Write the number after converting to targetBase into outpuFile
		*/
		void Processing_Convert(Qint num, int targetBase);

	public:
		/*
			This method is designed for Singleton design pattern. It will return an instance of Application class
			when it is invoked.
		*/
		static Application* getInstance();

		/*
			Parameter:
				Name of input file and output file
			Results:
				Run application with input reading in inputFile and writing output into outputFile
		*/
		void Start(const char* inputFile,const char* outputFile);
};
