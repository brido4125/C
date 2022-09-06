//
// Created by 홍창섭 on 2022/09/06.
//

#include <stdio.h>

int main(void){
    int x = 10, y = 20, tmp = 0;

    printf("Before : %d, %d \n", x, y);

    tmp = x;
    x = y;
    y = tmp;

    printf("After : %d, %d \n", x, y);

    return 0;
}