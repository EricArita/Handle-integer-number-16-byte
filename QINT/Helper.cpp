#include "Helper.h"

int Bit::turnOnBit(int num, int bitIndex) {
	return num | (1 << bitIndex);
}

int Bit::turnOffBit(int num, int bitIndex) {
	return num & (~(1 << bitIndex));
}

bool Bit::getBit(int num, int bitIndex) {
	return (num >> bitIndex) & 1;
}

int Bit::setBit(int num, int bitIndex, bool value) {
	if (value == 1)
		return Bit::turnOnBit(num, bitIndex);
	else
		return Bit::turnOffBit(num, bitIndex);
}