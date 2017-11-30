/* �ۑ�
2^300�𐳊m�Ɍv�Z����B
*/

/*
��(BASE)��0�ȏォ��(2^31)-1���\������������, �w��(EXPONENT)��0�ȏ�(2^31)-1�ȉ��̐���
�ɂ����ęp���v�Z���A2�`10�i��(RADIX)�ŕ\���ł��܂��B(0^0 = 1�ƂȂ�͎̂d�l)
�G���[������邽�߁AARRAY_DIGITS�̒l���p�̌�����菬�����Ƃ��̎��_�Ńv���O�������I�����܂��B

Visual Studio��C�R���p�C���ł͗v�f���ɕϐ�(const�C���q�t���܂�)���g���Ĕz���錾����R�[�h���ʂ�Ȃ��̂�
�p��̒l�̏��X��#define�ŃO���[�o�����O�t���萔�I�ɒ�`���Ă��܂�(#define�͊֐����Ŏg�p�����Ƃ��Ă��X�R�[�v�𖳎����Ăǂ��ł��g�p�ł���̂Œ���)�B
*/

#include <stdio.h>
#include <math.h>

#define BASE 7
#define EXPONENT 100
#define ARRAY_DIGITS 100
#define RADIX 10


/* 
 * �p��number_base�i���ł̌������擾���܂��B
 * math.h�ɂ͏�p�ΐ��Ǝ��R�ΐ��̉��Z����`����Ă��āA
 * �C�ӂ̒�őΐ������߂�ɂ͑ΐ��̒�̕ϊ��������g���܂��B
 * logarithm��int�^�ɃL���X�g���邱�Ƃŏ����_�ȉ���؂�̂ĂĂ��܂��B
 */
int getPowerDigits(int exponentation_base, int exponent, int number_base) {
	if (exponentation_base == 0) {
		return 1;
	}

	double logarithm = log((double)exponentation_base)/log((double)number_base) * exponent;
	int powerDigits = (int)logarithm + 1;

	return powerDigits;
}


int main(void) {
	int powerDigits = getPowerDigits(BASE, EXPONENT, RADIX);

	if (powerDigits > ARRAY_DIGITS) {
		printf("ARRAY_DIGITS��%d�ȏ�ɐݒ肵�Ă��������B\n", powerDigits);
		return 0;
	}
	
	int powerArray[ARRAY_DIGITS] = { 1 };

	int i, j, k;
	for (i = 0; i < EXPONENT; i++) {
		for (j = 0; j < ARRAY_DIGITS; j++) {
			powerArray[j] *= BASE;
		}
		for (k = 0; k < ARRAY_DIGITS; k++) {
			if (powerArray[k] >= RADIX) {
				powerArray[k + 1] += powerArray[k] / RADIX;
				powerArray[k] = powerArray[k] % RADIX;
			}
		}
	}

	printf("%d^%d = ", BASE, EXPONENT);
	int m;
	// �����̐擪��0�������Ȃ��悤�ɁAgetPowerDigits()�Ŏ擾�������������\������B
	for (m = powerDigits - 1; m >= 0; m--) {
		printf("%d", powerArray[m]);
	}
	printf(" (%d��)\n", powerDigits);

	return 0;
}
