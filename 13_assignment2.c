#include <stdio.h>
#include <math.h>

/*
 * 課題: 素因数分解
 * ある自然数nを入力し、nを素因数分解するプログラムを作成せよ
 * ただし、出力は以下のいずれかの形式で表記せよ(下段が望ましい)
 * 360 = 2 * 2 * 2 * 3 * 3 * 5
 * 360 = 2^3 * 3^2 * 5
 */

int isPrimeNumber(const int integer) {
	if (integer == 2) {
		return 1;
	}
	if (integer % 2 == 0) {
		return 0;
	}
	for (int i = 3; i <= sqrt(integer); i = i + 2) {
		if (integer%i == 0) {
			return 0;
		}
	}
	return 1;
}

int main(void) {
	int inputNumber;
	printf("2^31 - 1以下の自然数を入力してください\n");
	scanf_s("%d", &inputNumber);
	printf("%d = ", inputNumber);

	if (isPrimeNumber(inputNumber)) {
		printf("%d", inputNumber);
		return 0;
	}

	int i;
	int diviend = inputNumber;
	for (i = 2; i <= inputNumber; i++) {
		if (!isPrimeNumber(i)) {
			continue;
		}
		if (diviend%i == 0) {
			printf("%d ", i);
			break;
		}
	}

	diviend = diviend / i;

	for (; i <= inputNumber; i++) {
		if (!isPrimeNumber(i)) {
			continue;
		}
		while (diviend > 0) {
			if (diviend%i != 0) {
				break;
			}
			printf("* %d ", i);
			diviend = diviend / i;
		}
	}
	printf("\n");
	return 0;
}