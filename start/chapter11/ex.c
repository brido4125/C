//
// Created by 홍창섭 on 2022/10/21.
//
#include <stdio.h>

int main(void){
    int nData = 300;
    int *pnData = &nData;
    printf("int형 변수 nData의 값 : %d \n", nData);
    printf("int형 변수 nData의 주소 : %p \n", &nData);
    printf("포인터 pnData의 주소 : %p\n", pnData);
    printf("포인터 pnData가 간접지정한 값 : %d\n", *pnData);
    *pnData = 600;
    printf("int형 변수 nData의 값 : %d \n", nData);
    printf("int형 변수 nData의 주소 : %p \n", &nData);
    printf("포인터 pnData의 주소 : %p\n", pnData);
    printf("포인터 pnData가 간접지정한 값 : %d\n", *pnData);
}