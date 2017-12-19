/*
 * ����AB, BC, CA�����߂ē_P��Y���W��
 * �ł�X���W�̏������_��2�Ԗڂɏ������_��ʂ钼����艺�ɂ���A2�Ԗڂ�3�Ԗڂ̓_��ʂ钼�����傫���A
 */

#define DIMENSION 2
#define POINTS 4
#define ANGLES 3
#define A 0
#define B 1
#define C 2
#define P 3
#define X 0
#define Y 1
#define AB 0
#define BC 1
#define CA 2
#define SLOPE 0
#define Y_INTERCEPT 1

#include <stdio.h>

int main(void) {
    const char pointNames[POINTS] = { 'A', 'B', 'C', 'P' };
    const char coordinates[DIMENSION] = { 'X', 'Y' };
    double pointCoordinates[POINTS][DIMENSION];
    double lines[ANGLES][DIMENSION];

    int i,j;
    for (i = 0; i < POINTS; i++) {
        for (j = 0; j < DIMENSION; j++) {
            printf("�_%c %c���W: ", pointNames[i], coordinates[j]);
            scanf_s("%f", &pointCoordinates[i][j]);
        }
    }

    for (i = 0; i < ANGLES; i++) {
        if (pointCoordinates[i][X] >= pointCoordinates[(i + 1) % ANGLES][X]) {
            lines[i][SLOPE] = (pointCoordinates[i][Y] - pointCoordinates[(i + 1) % ANGLES][Y]) / (pointCoordinates[i][X] - pointCoordinates[(i + 1) % ANGLES][X]);
            lines[i][Y_INTERCEPT] = pointCoordinates[i][Y] - lines[i][SLOPE] * pointCoordinates[i][X];
        }
        else {
            lines[i][SLOPE] = (pointCoordinates[(i + 1) % ANGLES][Y] - pointCoordinates[i][Y]) / (pointCoordinates[(i + 1) % ANGLES][X] - pointCoordinates[i][X]);
            lines[i][Y_INTERCEPT] = pointCoordinates[(i + 1) % ANGLES][Y] - lines[i][SLOPE] * pointCoordinates[i][X];
        }
    }

    if (pointCoordinates[P][Y]>lines[AB][SLOPE] * pointCoordinates[P][X] + lines[AB][Y_INTERCEPT]) {
        printf("�_P�͎O�p�`ABC�̊O�ɂ���܂�\n");
        return 0;
    }
    if (pointCoordinates[P][Y]<lines[BC][SLOPE] * pointCoordinates[P][X] + lines[BC][Y_INTERCEPT]) {
        printf("�_P�͎O�p�`ABC�̊O�ɂ���܂�\n");
        return 0;
    }
    if (pointCoordinates[P][Y]<lines[CA][SLOPE] * pointCoordinates[P][X] + lines[CA][Y_INTERCEPT]){
        printf("�_P�͎O�p�`ABC�̊O�ɂ���܂�\n");
        return 0;
    }

    printf("�_P�͎O�p�`ABC�̓���(����AB,BC,CA����܂�)�ɂ���܂�\n");
    return 0;
}