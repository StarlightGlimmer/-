/* 演習
配列の要素を逆にするプログラムを作りたい。
以下の手順で作成せよ。
1. mainで配列 p[]=[3,7,4, ..... , 2]を作る(要素数・値はなんでもよい)
2. 配列pのポインタと要素数を関数subに渡す。
3. sub関数では、pの要素を逆に並べる。
(これによって配列pの内容が変更される)
4. mainｄ逆順になった配列pを表示する。
*/


#include <stdio.h>


void sub(int *ary, int elements){
	int i;
	int replace;
	for (i = 0; i <= elements/2 - 1; i++){
		replace = *(ary + (elements-1 - i));
		*(ary + (elements-1 - i)) = *(ary + i);
		*(ary + i) = replace;
	}
}


int main(void){
	int p[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	printf("初期配列: ");
	int i;
	for (i = 0; i < 10; i++){
		printf("%2d ", p[i]);
	}
	printf("\n");

	sub(p, 10);

	printf("　　逆順: ");
	int j;
	for (j = 0; j < 10; j++){
		printf("%2d ", p[j]);
	}
	printf("\n");
	return 0;
}