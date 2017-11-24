/* �ۑ�
�܂��A�ȉ��̓�̊֐������B
1. �z��array�̃|�C���^�Ɠ�̐���i, j��n���āA�͈�
array[i]�`array[j]���̍ŏ��l�̓Y��(�v�f�ԍ�)��Ԃ��֐�min_element
2. �ϐ�p�̃|�C���^�ƕϐ�q�̃|�C���^��n���āAp��q�̒l����������֐�swap

���ɁA���̓�̊֐����g���āA�z��array�̑S�v�f�������ɕ��ёւ��ďo�͂���v���O�������쐬����B
�������A�z��array�̗v�f�͂��ׂ�int�ŁA�v���O�������ő�����č\��Ȃ��B
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

	printf("�����z��: ");
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

	printf("�@�@����: ");
	int k;
	for (k = 0; k <ARRAY_SIZE - 1; k++){
		printf("%2d ", array[k]);
	}
	printf("\n");

	return 0;
}