//
// Created by 홍창섭 on 2022/09/06.
//

#include <stdio.h>

int main(void){
    int input = 0;
    int sum = 0;

    for (int i = 0; i < 3; ++i) {
        scanf("%d", &input);
        sum += input;
    }

    printf("sum = %d \n", sum);

    return 0;
}