/* 課題
2^300を正確に計算せよ。
*/

/*
底(BASE)は0以上かつ(2^31)-1より十分小さい整数, 指数(EXPONENT)は0以上(2^31)-1以下の整数
において冪を計算し、2～10進数(RADIX)で表示できます。(0^0 = 1となるのは仕様)
エラーを避けるため、ARRAY_DIGITSの値が冪の桁数より小さいとその時点でプログラムが終了します。

Visual StudioのCコンパイラでは要素数に変数(const修飾子付き含む)を使って配列を宣言するコードが通らないので
冪乗の値の諸々を#defineでグローバル名前付き定数的に定義しています(#defineは関数内で使用したとしてもスコープを無視してどこでも使用できるので注意)。
*/

#include <stdio.h>
#include <math.h>

#define BASE 7
#define EXPONENT 100
#define ARRAY_DIGITS 100
#define RADIX 10


/* 
 * 冪のnumber_base進数での桁数を取得します。
 * math.hには常用対数と自然対数の演算が定義されていて、
 * 任意の底で対数を求めるには対数の底の変換公式を使います。
 * logarithmをint型にキャストすることで小数点以下を切り捨てています。
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
		printf("ARRAY_DIGITSを%d以上に設定してください。\n", powerDigits);
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
	// 数字の先頭に0が続かないように、getPowerDigits()で取得した桁数だけ表示する。
	for (m = powerDigits - 1; m >= 0; m--) {
		printf("%d", powerArray[m]);
	}
	printf(" (%d桁)\n", powerDigits);

	return 0;
}
