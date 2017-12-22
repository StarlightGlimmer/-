/*
 * 確率の刻みを細かくするにつれて平均が3人へ近づいていくことが分かった
 * 
 * 確率0.100000刻みで平均2.700000人
 * 確率0.010000刻みで平均3.640000人
 * 確率0.001000刻みで平均2.914000人
 * 確率0.000100刻みで平均2.963800人
 * 確率0.000010刻みで平均2.984190人
 * 確率0.000001刻みで平均2.998857人
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
        printf("p = %lf: %d人\n", p, children);
    }

    double averageOfChildren = (double)childrenTotal / (trials - 1);
    printf("確率%lf刻みで平均%lf人\n", (double)1 / (trials - 1), averageOfChildren);

    return 0;
}