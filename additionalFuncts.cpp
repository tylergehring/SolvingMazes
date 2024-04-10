#include"additionalFuncts.h"

// calculates the int value of a string of numerical values
int strToInt(string str) {
	int size = str.size();

	int total = 0;

	for (int i = 0; i < size; i++) {
		total += ((int)str[i] - 48) * power(10, ((size-1)-i));
	}
	return total;
}

// raises a number to a power
int power(int x, int power) {
	if (power == 0) {
		return 1;
	}
	else {
		int total = x;
		for (int i = 1; i < power; i++) {
			total = total * x;
		}

		return total;
	}
}