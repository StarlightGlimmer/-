/* ‰Û‘è
2^300‚ğ³Šm‚ÉŒvZ‚¹‚æB
*/

#include <stdio.h>

#define BASE 2
#define EXPONENT 300
#define ARRAY_DIGITS 100
#define RADIX 10


int getExactDigit(int numberArray[ARRAY_DIGITS]) {
	int i;
	for (i = ARRAY_DIGITS - 1; i >= 0; i--) {
		if (numberArray[i] != 0) {
			return i + 1;
		}
	}
	return 1;
}


int main(void) {
	int powerArray[ARRAY_DIGITS] = { 1 };

	int i, j;
	for (i = 0; i < EXPONENT; i++) {
		for (j = ARRAY_DIGITS - 1; j >= 0; j--) {
			if (powerArray[j]*BASE >= RADIX) {
				powerArray[j + 1] += 1;
			}
			powerArray[j] = (powerArray[j]*BASE) % RADIX;
		}
	}

	printf("%d^%d = ", BASE, EXPONENT);
	int answerDigit = getExactDigit(powerArray);
	int k;
	for (k = answerDigit - 1; k >= 0; k--) {
		printf("%d", powerArray[k]);
	}
	printf("\n");

	return 0;
}
