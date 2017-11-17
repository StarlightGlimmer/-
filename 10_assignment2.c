/* ‰Û‘è
2^300‚ğ³Šm‚ÉŒvZ‚¹‚æB
*/

#include <stdio.h>

#define BASE 2
#define POWER 300
#define DIGITS 100



int getProductFirstDigit(int a, int b){
	int product[2] = { a*b };
	if (product[0] >= 10){
		product[1] = product[0] / 10;
		product[0] -= product[1] * 10;
	}
	return product[0];
}

int main(void){
	int twoToThe300thPower[DIGITS] = { 1 };
	
	int i, j;
	for (i = 0; i < POWER; i++){
		for (j = 1; j <= DIGITS; j++){
			if (twoToThe300thPower[DIGITS - j] < 5){
				twoToThe300thPower[DIGITS - j] *= BASE;
			}
			else{
				twoToThe300thPower[DIGITS - j] = getProductFirstDigit(BASE, twoToThe300thPower[DIGITS - j]);
				twoToThe300thPower[DIGITS - j +1] += 1;
			}
		}
	}

	int m;
	printf("2^%d = \n", POWER);
	for (m = 0; m < DIGITS; m++){
		printf("%d", twoToThe300thPower[DIGITS - m - 1]);
	}
	printf("\n");
	return 0;
}