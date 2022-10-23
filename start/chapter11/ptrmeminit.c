//
// Created by 홍창섭 on 2022/10/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int *pList = NULL, *pNewList = NULL;

    //A. int형 3개 배열 선언 및 정의(0 초기화)
    int aList[3] = {0};

    //B. int형 3개를 담을 수 있는 크기의 메모리를 동적으로 할당한 후
    // memset을 통해 메모리를 모두 0으로 초기화
    pList = (int *) malloc(sizeof(int) * 3);
    memset(pList,0,sizeof(int)*3);

    //C. int형 3개를 담을 수 있는 메모리를 0으로 초기화한 후 할당받음
    pNewList = (int *) calloc(3, sizeof(int));

    free(pList);
    free(pNewList);

    return 0;
}