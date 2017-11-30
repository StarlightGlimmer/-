/* 課題
まず、以下の二つの関数を作れ。
1. 配列arrayのポインタと2つの数字i, jを渡して、範囲
array[i]～array[j]内の最小値の添字(要素番号)を返す関数min_element
2. 変数pのポインタと変数qのポインタを渡して、pとqの値を交換する関数swap

次に、この二つの関数を使って、配列arrayの全要素を昇順に並び替えて出力するプログラムを作成せよ。
ただし、配列arrayの要素はすべてintで、プログラム中で代入して構わない。
*/

#define ARRAY_SIZE 10


#include <stdio.h>


int min_element(int *ary, int startingIndex, int endIndex){
	int idx;
	int minimum = *(ary+startingIndex);
	int minimumIndex = startingIndex;

	for (idx = startingIndex; idx <= endIndex; idx++){
		if (*(ary+idx) < minimum){
			minimum = *(ary + idx);
			minimumIndex = idx;
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


/* 整数の桁数(負の数は'-'も1桁に数える)を取得する */
int get_integer_digits(int integer) {
	int diviend = integer;
	int digits = 0;
	if (diviend < 0) digits = digits + 1;

	do {
		diviend = diviend / 10;
		digits = digits + 1;
	} while (diviend != 0);

	return digits;
}


/* 配列の要素の中で最も大きい桁数をget_integer_digits()を呼び出して取得する */
int get_maximum_digits_of_elements(int *ary, int elements) {
	int maximumDigits = 0;

	int idx;
	for (idx = 0; idx < elements; idx++) {
		if (get_integer_digits(*(ary + idx)) > maximumDigits) {
			maximumDigits = get_integer_digits(*(ary + idx));
		}
	}

	return maximumDigits;
}


/*
 *配列をインデックス0からelementsまで順に、その中の
 * get_maximum_digits_of_elements()で取得した最大桁数に合わせて表示する
 */
void print_array(int *ary, int elements) {
	int maximumDigits = get_maximum_digits_of_elements(ary, ARRAY_SIZE);
	int idx;
	for (idx = 0; idx < elements; idx++) {
		printf("%*d ", maximumDigits, *(ary + idx));
	}
	printf("\n");
}


int main(void){
	int array[ARRAY_SIZE] = { 10,9,8,7,6,5,4,3,2,1 };

	printf("初期配列: ");
	print_array(array, ARRAY_SIZE);
	
	int i;
	for (i = 0; i < ARRAY_SIZE - 1; i++){
		if (array[i] > array[min_element(array, i, ARRAY_SIZE - 1)]){
			swap(&array[i], &array[min_element(array, i, ARRAY_SIZE - 1)]);
		}

	}

	printf("　　昇順: ");
	print_array(array, ARRAY_SIZE);

	return 0;
}