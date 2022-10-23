//
// Created by 홍창섭 on 2022/10/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int *pList = NULL;

    pList = (int *) malloc(sizeof(int) * 2);
    memset(pList,1,sizeof (int)*3);

    pList[0] = 10;
    pList[1] = 20;
    pList[2] = 30;
    pList[3] = 40;

    for (int i = 0; i < 4; i++) {
        printf("%d\n", pList[i]);
    }
    free(pList);
    return 0;
}