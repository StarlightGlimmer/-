/*
 * ダーツが円に当たる確率は5^2pi/100 = pi/4である
 * つまり命中した確率に4を掛ければpiを求められる
 * プログラムでは半径1の円を4分割した扇形と一辺1の正方形を使用した
 * x,y座標に0～1の乱数を入れ、原点からの距離が円の半径radius以下であれば命中と判定
 * 
 * 出力結果：
 * 試行回数: 1000000
 * 命中: 785572
 * 外れ: 214428
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
    /* rand()/RAND_MAXで0～1までの小数座標を取得 */
    for (int i = 0; i < trials; i++) {
        double point[DIMENSION] = { (double)rand() / RAND_MAX, (double)rand() / RAND_MAX };
        printf("%d回目: ", i + 1);
        if (sqrt(pow(point[x], 2) + pow(point[y], 2)) <= radius) {
            printf("命中\n");
            hit++;
        }
        else {
            printf("外れ\n");
        }
    }
    
    const double pi =(double) hit / trials * 4;
    printf("\n試行回数: %d\n命中: %d\n外れ: %d\n", trials, hit, trials - hit);
    printf("pi = %lf\n", pi);

    return 0;
}