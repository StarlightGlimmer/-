/* ���K
�z��̗v�f���t�ɂ���v���O��������肽���B
�ȉ��̎菇�ō쐬����B
1. main�Ŕz�� p[]=[3,7,4, ..... , 2]�����(�v�f���E�l�͂Ȃ�ł��悢)
2. �z��p�̃|�C���^�Ɨv�f�����֐�sub�ɓn���B
3. sub�֐��ł́Ap�̗v�f���t�ɕ��ׂ�B
(����ɂ���Ĕz��p�̓��e���ύX�����)
4. main���t���ɂȂ����z��p��\������B
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
	
	printf("�����z��: ");
	int i;
	for (i = 0; i < 10; i++){
		printf("%2d ", p[i]);
	}
	printf("\n");

	sub(p, 10);

	printf("�@�@�t��: ");
	int j;
	for (j = 0; j < 10; j++){
		printf("%2d ", p[j]);
	}
	printf("\n");
	return 0;
}