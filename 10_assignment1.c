/* 課題
3行3列の行列A, Bに対して、行列の積ABを計算するプログラムを作成せよ
ただし、A, Bの値はあらかじめコード中に代入してよい
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

	printf("行列積AB=\n");
	int m, n;
	for (m = 0; m < ROWS; m++){
		for (n = 0; n < COLUMNS; n++){
			printf("%3d ", productMatrix[m][n]);
		}
		printf("\n");
	}

	return 0;
}