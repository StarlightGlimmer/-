/*
 * �O���ۑ�F��z��
 * ���A4�n�_(A�`D�s)�ɂ��ꂼ��200kg�̉ו�������B
 * ������Ɉȉ��̂悤�Ȋ����œ����ɔz�B���s���B
 * �����������J��Ԃ��ƍŏI�I�ɂǂ̂悤�ȏ�ԂɂȂ邩���V�~�����[�V��������B
 * [A�s����] B:20% C:40% D:30%
 * [B�s����] A:
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

        /* �e�s���瑼�̎s�ւ̔z�B�d�ʂ�deriveryMass�ɑ�� */
		for (j = 0; j < CITIES; j++) {
			for (k = 0; k < CITIES; k++) {
				if (j != k) {
					deliveryMass[j][k] = packageMassInKilogram[j] * massPercentage[j][k] / 100;
				}
			}
		}
        /* ���݂̉ו��̏d�ʂ���z�B�d�ʕ������� */
		for (j = 0; j < CITIES; j++) {
			for (k = 0; k < CITIES; k++) {
				if (j != k) {
					packageMassInKilogram[j] -= deliveryMass[j][k];
				}
			}
		}

        /* �z�B����Ă����ו��̏d�ʂ����݂̉ו��̏d�ʂɑ��� */
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