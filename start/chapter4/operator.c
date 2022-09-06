//
// Created by 홍창섭 on 2022/09/06.
//

#include <stdio.h>

int main(void){
    int nResult = 0;

    nResult = 3 + 4 - 5;
    printf("결과 = %d \n", nResult);

    int x = 1;
    char y = 'A';

    printf("%d\n", x + y);
    printf("%c\n", x + y);
    printf("%lu\n", sizeof(x + y));
    return 0;
}