//
// Created by 홍창섭 on 2022/09/06.
//

#include <stdio.h>

int main(void){
    int x = 10;

    printf("%d\n", x * 10);
    printf("%d\n", x * 10.0);

    printf("%d\n", x / 10);

    //int / int => int로 소수점 이하 버림
    printf("%d\n", 5 / 2);

    printf("%f\n", 5.0 / 2);

    return 0;
}