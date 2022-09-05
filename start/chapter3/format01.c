//
// Created by 홍창섭 on 2022/08/30.
// option + shift + e

#include <stdio.h>

int main(void){
    printf("%d\n", 1234);
    printf("%d,%d\n", 1234, -5678);

    printf("%+d,%-d\n", 1234, -5678);

    printf("%8d\n",1234);
    printf("%08d\n",1234);
    printf("%-8d\n",1234);


    return 0;
}


