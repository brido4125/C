//
// Created by 홍창섭 on 2022/08/30.
//
#include <stdio.h>

int main(void){
    printf("%d\n", 10);
    printf("%u\n", 10);
    printf("%d\n", 10U);
    printf("%u\n", 10U);

    printf("%d\n", 2147483647);
    printf("%d\n", 2147483648);//부호를 넘어섬
    printf("%u\n", 2147483648);

    printf("%d\n", -1);
    printf("%u\n", -1);//음수가 없는 범위에서 -1로 가면 가장 큰 수 출력

    return 0;
}
