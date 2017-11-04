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
	int a, b, c, d;					// �����̐���

	printf("\na/b + c/d ���v�Z���܂��B���R������͂��Ă��������B\na = "); scanf_s("%d", &a);
	printf("b = "); scanf_s("%d", &b);
	printf("c = "); scanf_s("%d", &c);
	printf("d = "); scanf_s("%d", &d);

	int Numerator = a*d + b*c;
	int Denominator = b*d;

	int gcdOfNumeratorAndDenominator = Gcd(Numerator, Denominator);
	int reductedNumerator = Numerator / gcdOfNumeratorAndDenominator;
	int reductedDenominator = Denominator / gcdOfNumeratorAndDenominator;

	if (reductedDenominator == 1) {
		printf("(%d)/(%d) + (%d)/(%d) = %d\n", a, b, c, d, reductedNumerator);
	}
	else {
		printf("(%d)/(%d) + (%d)/(%d) = %d/%d\n", a, b, c, d, reductedNumerator, reductedDenominator);
	}
}
