#include <stdio.h>


int Gcd(const int a, const int b) {
	int num1 = a;
	int num2 = b;
	while (num1 != 0 && num2 != 0) {
		if (num1 >= num2) {
			num1 = num1 % num2;
		}
		else {
			num2 = num2 & num1;
		}
	}
	
	int greatestCommonDivisor = 0;
	if (num1 > num2) {
		greatestCommonDivisor = num1;
	}
	else {
		greatestCommonDivisor = num2;
	}

	return greatestCommonDivisor;
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
	else if (denominator / Gcd(numerator, denominator) == 1) {
		printf("(%d)/(%d) + (%d)/(%d) = %d\n", a, b, c, d, numerator / Gcd(numerator, denominator));
	}
	else {
		printf("(%d)/(%d) + (%d)/(%d) = %d/%d\n", a, b, c, d, numerator / Gcd(numerator, denominator), denominator / Gcd(numerator, denominator));
	}
}
