/*
 * �m���̍��݂��ׂ�������ɂ�ĕ��ς�3�l�֋߂Â��Ă������Ƃ���������
 * 
 * �m��0.100000���݂ŕ���2.700000�l
 * �m��0.010000���݂ŕ���3.640000�l
 * �m��0.001000���݂ŕ���2.914000�l
 * �m��0.000100���݂ŕ���2.963800�l
 * �m��0.000010���݂ŕ���2.984190�l
 * �m��0.000001���݂ŕ���2.998857�l
 */

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int isMale(const double sexDecimal, const double femaleThreshold) {
    if (sexDecimal <= femaleThreshold) {
        return 1;
    }
    return 0;
}

int main(void) {
    srand(time(NULL));
    const int trials = 10001;
    int childrenTotal = 0;
    for (int i = 0; i < trials; i++) {
        const double p = (double) i / (trials - 1);
        const int sexOfFirstChild = isMale((double)rand() / RAND_MAX, p);
        int children = 1;
        while (1) {
            children++;
            if (sexOfFirstChild == isMale((double)rand() / RAND_MAX, p)) {
                break;
            }
        }
        childrenTotal += children;
        printf("p = %lf: %d�l\n", p, children);
    }

    double averageOfChildren = (double)childrenTotal / (trials - 1);
    printf("�m��%lf���݂ŕ���%lf�l\n", (double)1 / (trials - 1), averageOfChildren);

    return 0;
}