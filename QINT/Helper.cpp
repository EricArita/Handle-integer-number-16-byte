#include "Helper.h"

int Bit::turnOnBit(int num, int bitIndex) {
	return num | (1 << bitIndex);
}

int Bit::turnOffBit(int num, int bitIndex) {
	return num | (~(1 << bitIndex));
}

int Bit::getBit(int num, int bitIndex) {
	return (num >> bitIndex) & 1;
}