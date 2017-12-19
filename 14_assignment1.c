/*
 * 前半課題：宅配便
 * 今、4地点(A～D市)にそれぞれ200kgの荷物がある。
 * ある日に以下のような割合で同時に配達を行う。
 * これを何回も繰り返すと最終的にどのような状態になるかをシミュレーションせよ。
 * [A市から] B:20% C:40% D:30%
 * [B市から] A:
 * 
 */

#define CITIES 4

#include <stdio.h>

int main(void) {
	const char cityNames[CITIES] = { 'A', 'B', 'C', 'D' };
	double packageMassInKilogram[CITIES] = { 200.0, 200.0, 200.0, 200.0 };
	const int massPercentage[CITIES][CITIES] = { { 10, 20, 40, 30 }, {50, 20, 20, 10 }, { 10, 20, 50, 20 }, { 10, 20, 40, 30 } };
	double deliveryMass[CITIES][CITIES];
	const int days = 10;

	int i, j, k;
	for (i = 0; i < days; i++) {

        /* 各市から他の市への配達重量をderiveryMassに代入 */
		for (j = 0; j < CITIES; j++) {
			for (k = 0; k < CITIES; k++) {
				if (j != k) {
					deliveryMass[j][k] = packageMassInKilogram[j] * massPercentage[j][k] / 100;
				}
			}
		}
        /* 現在の荷物の重量から配達重量分を引く */
		for (j = 0; j < CITIES; j++) {
			for (k = 0; k < CITIES; k++) {
				if (j != k) {
					packageMassInKilogram[j] -= deliveryMass[j][k];
				}
			}
		}

        /* 配達されてきた荷物の重量を現在の荷物の重量に足す */
		for (j = 0; j < CITIES; j++) {
			for (k = 0; k < CITIES; k++) {
				if (j != k) {
						packageMassInKilogram[j] += deliveryMass[k][j];
				}
			}
		}
	}

	for (i = 0; i < CITIES; i++) {
		printf("%c: %.0f kg\n", cityNames[i], packageMassInKilogram[i]);
	}

	return 0;
}