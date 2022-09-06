//
// Created by 홍창섭 on 2022/09/06.
//

#include <stdio.h>

int main(void){
    char ch = 'A';

    printf("%c\n", ch);

    printf("%c\n", ch + 1);
    printf("%c\n", 'A' + 1);

    printf("%d\n", 5.1 + 2);//double + int = double
    printf("%f\n", 5.1 + 2);
    return 0;
}