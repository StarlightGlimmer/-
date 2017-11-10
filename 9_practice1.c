/* 演習1
0～9のいずれかの数字が任意回入力され、
最後に-1が入力された時、0～9の数字が
それぞれ何回入力されたのかを数えて出力するプログラムを作成せよ。

入力例： 3, 5, 3, 1, 8, -1
出力例：1が1回、3が2回、5が1回、8が1回
*/

#include <stdio.h>
#define ONE_DIGIT_MAXIMUM 9


void main(void) {
	printf("0～9の整数を任意回入力してください。-1を入力すると終了します。\n");
	
	int n[ONE_DIGIT_MAXIMUM + 1] = { 0 };

	while(1){
		int InputtedNumber;
		scanf_s("%d", &InputtedNumber);
		if (InputtedNumber == -1){
			break;
		}
		n[InputtedNumber] += 1;
	}

	int PrintLoopVariable;
	for (PrintLoopVariable = 0; PrintLoopVariable <= ONE_DIGIT_MAXIMUM; PrintLoopVariable++){
		if (n[PrintLoopVariable] == 0) {
			continue;
		}
		printf("%dが%d回　", PrintLoopVariable, n[PrintLoopVariable]);
	}
	printf("\n");
}
