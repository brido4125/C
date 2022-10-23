//
// Created by 홍창섭 on 2022/10/23.
//

#include <stdio.h>

int main(void){
    int aList[5] = {0};
    int *pnData = aList;
    printf("aList[0] : %d \n", aList[0]);
    *pnData = 20;
    printf("aList[0] : %d \n", aList[0]);
    printf("aList[0]의 주소 : %p \n", pnData);

    printf("aList[1] : %d \n", aList[1]);
    int *pnData1 = (aList + 1);//aList는 (pnData + 0)
    *pnData1 = 30;
    printf("aList[1] : %d \n", aList[1]);
    printf("aList[1]의 주소 : %p \n", pnData1);
}