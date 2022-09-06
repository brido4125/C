//
// Created by 홍창섭 on 2022/09/06.
//

#include <stdio.h>

int main(void){
    int x = 0;
    int y = 0;
    printf("두 정수를 입력하세요 : ");
    scanf("%d%d", &x, &y);

    int sum = x + y;

    double avg = sum / 2.0;

    printf("평균은 %.2f 입니다.\n", avg);

    return 0;
}