//
// Created by 홍창섭 on 2022/09/04.
//

#include <stdio.h>

int main(void){
    printf("%d\n", sizeof(123.456F));
    printf("%d\n", sizeof(123.456));

    printf("%f\n",123.456F);
    printf("%f\n",123.456);

    float sum = 0;
    double sum_d = 0;

    for (int i = 0; i < 50; i++) {
        sum += 0.1F;
        sum_d += 0.1;
    }

    printf("sum by float = %f\n",sum);
    printf("sum by double = %f\n",sum_d);

    return 0;
}