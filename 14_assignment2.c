/*
 * 直線AB, BC, CAを求めて点PのY座標が
 * 最もX座標の小さい点と2番目に小さい点を通る直線より下にあり、2番目と3番目の点を通る直線より大きく、
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
            printf("点%c %c座標: ", pointNames[i], coordinates[j]);
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
        printf("点Pは三角形ABCの外にあります\n");
        return 0;
    }
    if (pointCoordinates[P][Y]<lines[BC][SLOPE] * pointCoordinates[P][X] + lines[BC][Y_INTERCEPT]) {
        printf("点Pは三角形ABCの外にあります\n");
        return 0;
    }
    if (pointCoordinates[P][Y]<lines[CA][SLOPE] * pointCoordinates[P][X] + lines[CA][Y_INTERCEPT]){
        printf("点Pは三角形ABCの外にあります\n");
        return 0;
    }

    printf("点Pは三角形ABCの内部(直線AB,BC,CA上を含む)にあります\n");
    return 0;
}