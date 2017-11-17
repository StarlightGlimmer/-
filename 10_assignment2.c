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

	// �ŏ�ʂ̌����珇�Ɋ|���Z��i�߂�B�|���Z�̌J��オ���1��̌��ɑ����A���݂̌���1�̈ʂ̐��������B�����EXPONENT��J��Ԃ��B
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

	// �����̐擪��0�������Ȃ��悤�ɁAgetExactDigit()�Ŏ擾�������������\������B
	for (k = answerDigit - 1; k >= 0; k--) {
		printf("%d", powerArray[k]);
	}
	printf("\n");

	return 0;
}
