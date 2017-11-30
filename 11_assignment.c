/* �ۑ�
�܂��A�ȉ��̓�̊֐������B
1. �z��array�̃|�C���^��2�̐���i, j��n���āA�͈�
array[i]�`array[j]���̍ŏ��l�̓Y��(�v�f�ԍ�)��Ԃ��֐�min_element
2. �ϐ�p�̃|�C���^�ƕϐ�q�̃|�C���^��n���āAp��q�̒l����������֐�swap

���ɁA���̓�̊֐����g���āA�z��array�̑S�v�f�������ɕ��ёւ��ďo�͂���v���O�������쐬����B
�������A�z��array�̗v�f�͂��ׂ�int�ŁA�v���O�������ő�����č\��Ȃ��B
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


/* �����̌���(���̐���'-'��1���ɐ�����)���擾���� */
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


/* �z��̗v�f�̒��ōł��傫��������get_integer_digits()���Ăяo���Ď擾���� */
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
 *�z����C���f�b�N�X0����elements�܂ŏ��ɁA���̒���
 * get_maximum_digits_of_elements()�Ŏ擾�����ő包���ɍ��킹�ĕ\������
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

	printf("�����z��: ");
	print_array(array, ARRAY_SIZE);
	
	int i;
	for (i = 0; i < ARRAY_SIZE - 1; i++){
		if (array[i] > array[min_element(array, i, ARRAY_SIZE - 1)]){
			swap(&array[i], &array[min_element(array, i, ARRAY_SIZE - 1)]);
		}

	}

	printf("�@�@����: ");
	print_array(array, ARRAY_SIZE);

	return 0;
}