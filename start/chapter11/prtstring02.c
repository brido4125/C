//
// Created by 홍창섭 on 2022/10/23.
//

#include <stdio.h>
#include <string.h>

int main(void){
    char szBuffer[16] = {"Hello"};
    char *pszData = szBuffer;

    while (*pszData != '\0') {
        pszData += 1;
    }

    printf("Length = %lu\n", pszData - szBuffer);

}