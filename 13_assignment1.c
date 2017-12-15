#include <stdio.h>
#include <time.h>

/*
* 課題：素数判定
* nを2～(n-1)まで割って1度でも余りが0になったら素数でない
* という方法で素数を判定するプログラムを作成する。
*
* 続き：
* これを改良して300000までのすべての素数を表示するプログラムを作成する。
* 提出物
* (1) プログラム
* (2) 実行時間 (以下を参照 https://speakerdeck.com/jnlp/ji-chu-qing-bao-chu-li-yan-xi-bu-zu-shi-xing-shi-jian-falsece-ding)
* (3) どこをどのように改良したかという説明
*/

/*
 * 実行時間：0.966 [s]
 * 
 * 改良した点：
 * 変数を減らすために、一般に好ましくはないがマジックナンバーを使用
 * √300000 ≒ 548 以上で割っても意味がないため、以降を省略
 */

int isPrimeNumber(const int integer) {
	if (integer == 2) {
		return 1;
	}
	for (int i = 3; i < 548; i = i+2) {
		if (integer%i == 0) {
			return 0;
		}
	}
	return 1;
}

void makePrimeNumberList(const int *ary) {
	for (int idx = 0;;idx++)
}

int main(void) {
	const clock_t start_time = clock();
	int primeNumbers[500] = { 0 };
	for (int i = 2; i <= 300000; i++) {
		if (isPrimeNumber(i)) {
			printf("%d ", i);
		}
	}

	const clock_t end_time = clock();
	printf("time = %.3f\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
	return 0;
}