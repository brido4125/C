//
// Created by 홍창섭 on 2022/09/06.
//

#include <stdio.h>

int main(void){
    int input = 0;
    printf("초(second)를 입력하세요 : ");
    scanf("%d", &input);

    int second = input % 60;
    int minute = input / 60;
    int hour = minute / 60;

    printf("Hour = %d\n", hour);
    printf("minute = %d\n", minute);
    printf("second = %d\n", second);

    return 0;
}