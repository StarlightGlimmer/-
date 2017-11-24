/* 課題
まず、以下の二つの関数を作れ。
1. 配列arrayのポインタと二つの数字i, jを渡して、範囲
array[i]～array[j]内の最小値の添字(要素番号)を返す関数min_element
2. 変数pのポインタと変数qのポインタを渡して、pとqの値を交換する関数swap

次に、この二つの関数を使って、配列arrayの全要素を昇順に並び替えて出力するプログラムを作成せよ。
ただし、配列arrayの要素はすべてintで、プログラム中で代入して構わない。
*/

#define ARRAY_SIZE 10


#include <stdio.h>


int min_element(int *ary, int from, int to){
	int i;
	int minimum = ary[from];
	int minimumIndex = 0;
	for (i = from; i <= to; i++){
		if (ary[i] < minimum){
			minimum = ary[i];
			minimumIndex = i;
		}
	}
	return minimumIndex;
}


void swap(int *a, int *b){
	int replace;
	replace = *a;
	*a = *b;
	*b = replace;
}

int isSorted(int *ary, int elements){
	int i;
	for (i = 0; i < elements-1; i++){
		if (ary[i] > ary[i + 1]){
			return 0;
		}
	}
	return 1;
}

int main(void){
	int array[ARRAY_SIZE] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	printf("初期配列: ");
	int i;
	for (i = 0; i < ARRAY_SIZE; i++){
		printf("%2d ", array[i]);
	}
	printf("\n");
	
	int j;
	for (j = 0; j < ARRAY_SIZE - 1; j++){
		if (array[j] != array[min_element(array, j, ARRAY_SIZE - 1)]){
			swap(&array[j], &array[min_element(array, j, ARRAY_SIZE - 1)]);
		}
		if (isSorted(array, ARRAY_SIZE)){
			break;
		}
	}

	printf("　　昇順: ");
	int k;
	for (k = 0; k <ARRAY_SIZE - 1; k++){
		printf("%2d ", array[k]);
	}
	printf("\n");

	return 0;
}