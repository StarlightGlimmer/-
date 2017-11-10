/* �ۑ�
p[0]�`p[9]�ɔC�ӂ̐�������͂���B������ȉ��̕��@�ŏ���(���ˑ�)�ɕ��ёւ��ďo�͂���B
(1) p[0] > p[1]�Ȃ�l����������B
(2) p[1] > p[2]�Ȃ�l����������B
......
(9) p[8] > p[9]�Ȃ�l����������B
(10) (1)�`(9)�̑�������񂩌J��Ԃ��B
*/


#include <stdio.h>


int SortingIsFinished(int a[10]){
	int i;
	for (i = 0; i < 9; i++){
		if (a[i] > a[i + 1]){
			return 0;
		}
	}
	return 1;
}


void main(void){
	printf("�C�ӂ̐�����10���͂��Ă�������\n");
	int p[10] = { 0 };

	int i;
	for (i = 0; i <= 9; i++){
		scanf_s("%d", &p[i]);
	}
	
	while (1){
		int temp; // �v�f�����p�̈ꎞ�ޔ���
		int j;
		for (j = 0; j < 9; j++){
			if (p[j] > p[j + 1]){
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}

		if (SortingIsFinished(p)){
			break;
		}
	}

	int k;
	for (k = 0; k <= 9; k++){
		printf("%d ", p[k]);
	}
	printf("\n");
}
