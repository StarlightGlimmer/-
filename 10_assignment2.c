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

	// 最上位の桁から順に掛け算を進める。掛け算の繰り上がりを1つ上の桁に足し、現在の桁に1の位の数字を代入。これをEXPONENT回繰り返す。
	for (i = 0; i < EXPONENT; i++) {
		for (j = ARRAY_DIGITS - 1; j >= 0; j--) {
			if (powerArray[j]*BASE >= RADIX) {
				powerArray[j + 1] += (powerArray[j]*BASE) / RADIX;
			}
			powerArray[j] = (powerArray[j]*BASE) % RADIX;
		}
	}

	printf("%d^%d = ", BASE, EXPONENT);
	int answerDigit = getExactDigit(powerArray);
	int k;

	// 数字の先頭に0が続かないように、getExactDigit()で取得した桁数だけ表示する。
	for (k = answerDigit - 1; k >= 0; k--) {
		printf("%d", powerArray[k]);
	}
	printf("\n");

	return 0;
}
