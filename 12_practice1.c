/*
 * 演習：文字変換器
 * キーボードからEOF(Ctrl+Z)が押されるまで文字(列)を読み込んで、
 * 大文字なら小文字に変換し、
 * 小文字なら大文字に変換し、
 * それ以外はそのまま画面に出力するプログラムを作成せよ。
 * なお、処理は文字単位、文字列単位のどちらで行ってもよい。
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
	printf("1字ずつ入力してください\n");
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
