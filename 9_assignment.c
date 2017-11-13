/* 課題
p[0]～p[9]に任意の整数を入力する。これを以下の方法で昇順(小⇒大)に並び替えて出力せよ。
(1) p[0] > p[1]なら値を交換する。
(2) p[1] > p[2]なら値を交換する。
......
(9) p[8] > p[9]なら値を交換する。
(10) (1)～(9)の操作を何回か繰り返す。
*/


#include <stdio.h>

#define NUM_OF_INPUT_INTEGERS 10


int SortingIsFinished(int a[NUM_OF_INPUT_INTEGERS]){
	int i;
	for (i = 0; i < NUM_OF_INPUT_INTEGERS - 1; i++){
		if (a[i] > a[i + 1]){
			return 0;
		}
	}
	return 1;
}


void main(void){
	printf("-(2^31)～(2^31)-1の整数を10個入力してください\n");
	int p[NUM_OF_INPUT_INTEGERS] = { 0 };

	int i;
	for (i = 0; i <= NUM_OF_INPUT_INTEGERS - 1; i++){
		scanf_s("%d", &p[i]);
	}
	
	while (1){
		int temp; // 要素交換用の一時退避所
		int j;
		for (j = 0; j < NUM_OF_INPUT_INTEGERS - 1; j++){
			if (p[j] > p[j + 1]){
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}

		if (SortingIsFinished(p)){
			break;
		}
	}

	int k;
	for (k = 0; k <= NUM_OF_INPUT_INTEGERS - 1; k++){
		printf("%d ", p[k]);
	}
	printf("\n");
}
