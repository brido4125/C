//
// Created by 홍창섭 on 2022/10/21.
//

#include <stdio.h>

int Add(int a, int b){
    int nResult; //지역변수 + 자동변수
    nResult = a + b;
    return nResult;
}

int main(void){
    int nResult; //서로 다른 scope
    nResult = Add(3, 4);

    printf("%d", nResult);
    return 0;
}