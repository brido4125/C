//
// Created by 홍창섭 on 2022/08/30.
//
#include <stdio.h>

int main(void) {
    long long int lldData = 4294967295LL;

    printf("%d\n", lldData);
    printf("%u\n", lldData);

    //usigned가 나타낼수 있는 최대 정수 범위 밖, 즉 32bit 이상의 크기가 필요한 숫자
    printf("%u\n", lldData+1);
    printf("%u\n", lldData+2);
    printf("%u\n", lldData+3);

    printf("%lld\n", lldData+1);
    printf("%lld\n", lldData+2);
    printf("%lld\n", lldData+3);

    return 0;
}
