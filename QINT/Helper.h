#pragma once
#include "Qint.h"

class Bit{
	public:	
		//
		//Turn on one bit at index position of num of int type
		//
		static int turnOnBit(int num, int bitIndex);

		//
		//Turn off one bit at index position of num of int type
		//
		static int turnOffBit(int num, int bitIndex);

		//get the value of bit at bitIndex position of num
		static int getBit(int num, int bitIndex);
};

