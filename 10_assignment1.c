/* �ۑ�
3�s3��̍s��A, B�ɑ΂��āA�s��̐�AB���v�Z����v���O�������쐬����
�������AA, B�̒l�͂��炩���߃R�[�h���ɑ�����Ă悢
*/

#include <stdio.h>


#define ROWS 3
#define COLUMNS 3


int main(void){
	int matrixA[ROWS][COLUMNS] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int matrixB[ROWS][COLUMNS] = { { 9, 8, 7 }, { 6, 5, 4 }, { 3, 2, 1 } };

	int productMatrix[ROWS][COLUMNS] = { 0 };

	int i, j, k;
	for (i = 0; i < ROWS; i++){
		for (j = 0; j < COLUMNS; j++){
			for (k = 0; k < COLUMNS; k++){
					productMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}

	printf("�s���AB=\n");
	int m, n;
	for (m = 0; m < ROWS; m++){
		for (n = 0; n < COLUMNS; n++){
			printf("%3d ", productMatrix[m][n]);
		}
		printf("\n");
	}

	return 0;
}