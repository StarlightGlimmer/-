#include <stdio.h>


int gcd(const int a, const int b) {
	int num1 = a;
	int num2 = b;
	while (num1 != num2) {
		while (num1 > num2) num1 -= num2;
		while (num2 > num1) num2 -= num1;
	}
	return num1;
}


void main(void) {
	int a, b, c, d;					// 分数の数字
	int numerator, denominator;		// 分子と分母

	printf("\na/b + c/d を計算します。自然数を入力してください。\na = "); scanf_s("%d", &a);
	printf("b = "); scanf_s("%d", &b);
	printf("c = "); scanf_s("%d", &c);
	printf("d = "); scanf_s("%d", &d);

	numerator = a*d + b*c;
	denominator = b*d;

	if (numerator == 0) {
		printf("(%d)/(%d) + (%d)/(%d) = 0\n", a, b, c, d);
	}
	else if (denominator / gcd(numerator, denominator) == 1) {
		printf("(%d)/(%d) + (%d)/(%d) = %d\n", a, b, c, d, numerator / gcd(numerator, denominator));
	}
	else {
		printf("(%d)/(%d) + (%d)/(%d) = %d/%d\n", a, b, c, d, numerator / gcd(numerator, denominator), denominator / gcd(numerator, denominator));
	}
}
