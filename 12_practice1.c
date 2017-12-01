/*
 * ���K�F�����ϊ���
 * �L�[�{�[�h����EOF(Ctrl+Z)���������܂ŕ���(��)��ǂݍ���ŁA
 * �啶���Ȃ珬�����ɕϊ����A
 * �������Ȃ�啶���ɕϊ����A
 * ����ȊO�͂��̂܂܉�ʂɏo�͂���v���O�������쐬����B
 * �Ȃ��A�����͕����P�ʁA������P�ʂ̂ǂ���ōs���Ă��悢�B
 */

#define DIFFERENCE_BETWEEN_UPPER_AND_LOWER_ASCII 32
#define UPPER_A_CODE_ASCII 65
#define LOWER_A_CODE_ASCII 97
#define NUMBER_OF_ALPHABETS 26
#define MAX_STRING_SIZE 100

#include <stdio.h>

int is_upper_case(const int ascii_code) {
	if (ascii_code<UPPER_A_CODE_ASCII
		|| ascii_code>UPPER_A_CODE_ASCII + (NUMBER_OF_ALPHABETS - 1)) {
		return 0;
	}
	return 1;
}

int is_lower_case(const int ascii_code) {
	if (ascii_code<LOWER_A_CODE_ASCII
		|| ascii_code>LOWER_A_CODE_ASCII + (NUMBER_OF_ALPHABETS - 1)) {
		return 0;
	}
	return  1;
}

void lower_case(int *ascii_c) {
	*ascii_c += DIFFERENCE_BETWEEN_UPPER_AND_LOWER_ASCII;
}

void upper_case(int *ascii_c) {
	*ascii_c -= DIFFERENCE_BETWEEN_UPPER_AND_LOWER_ASCII;
}

int main(void) {
	printf("1�������͂��Ă�������\n");
	int ch;
	while ((ch = getchar()) != EOF) {
		if (is_upper_case(ch)) {
			lower_case(&ch);
		}
		else if (is_lower_case(ch)) {
			upper_case(&ch);
		}
		putchar(ch);
	}

	return 0;
}
