/* ���K1
0�`9�̂����ꂩ�̐������C�Ӊ���͂���A
�Ō��-1�����͂��ꂽ���A0�`9�̐�����
���ꂼ�ꉽ����͂��ꂽ�̂��𐔂��ďo�͂���v���O�������쐬����B

���͗�F 3, 5, 3, 1, 8, -1
�o�͗�F1��1��A3��2��A5��1��A8��1��
*/

#include <stdio.h>
#define ONE_DIGIT_MAXIMUM 9


void main(void) {
	printf("0�`9�̐�����C�Ӊ���͂��Ă��������B-1����͂���ƏI�����܂��B\n");
	
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
		printf("%d��%d��@", PrintLoopVariable, n[PrintLoopVariable]);
	}
	printf("\n");
}
