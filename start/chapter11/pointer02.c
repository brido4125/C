//
// Created by 홍창섭 on 2022/10/23.
//

#include <stdio.h>

int main(void){
    int x = 10;
    int *pnData = &x; // 이름이 x인 메모의 주소값이 pnData
    printf("x : %d \n", x);
    printf("x의 메모리 주소 : %p \n", pnData);
    *pnData = 20;
    printf("변경 후 x : %d \n", x);


}