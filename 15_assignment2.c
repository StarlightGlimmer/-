/*
 * �_�[�c���~�ɓ�����m����5^2pi/100 = pi/4�ł���
 * �܂薽�������m����4���|�����pi�����߂���
 * �v���O�����ł͔��a1�̉~��4����������`�ƈ��1�̐����`���g�p����
 * x,y���W��0�`1�̗��������A���_����̋������~�̔��aradius�ȉ��ł���Ζ����Ɣ���
 * 
 * �o�͌��ʁF
 * ���s��: 1000000
 * ����: 785572
 * �O��: 214428
 * pi = 3.142288
 */

#define DIMENSION 2

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>



int main(void) {
    srand(time(NULL));
    const int trials = 1000000;
    const double radius = 1.0;
    const int x = 0;
    const int y = 1;
    int hit = 0;
    /* rand()/RAND_MAX��0�`1�܂ł̏������W���擾 */
    for (int i = 0; i < trials; i++) {
        double point[DIMENSION] = { (double)rand() / RAND_MAX, (double)rand() / RAND_MAX };
        printf("%d���: ", i + 1);
        if (sqrt(pow(point[x], 2) + pow(point[y], 2)) <= radius) {
            printf("����\n");
            hit++;
        }
        else {
            printf("�O��\n");
        }
    }
    
    const double pi =(double) hit / trials * 4;
    printf("\n���s��: %d\n����: %d\n�O��: %d\n", trials, hit, trials - hit);
    printf("pi = %lf\n", pi);

    return 0;
}