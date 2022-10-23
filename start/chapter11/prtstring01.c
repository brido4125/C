//
// Created by 홍창섭 on 2022/10/23.
//

#include <stdio.h>
#include <string.h>

int main(void){
    char szBuffer[16] = {"Hello"};
    char *pszData = szBuffer;
    int nLength = 0;

    while (*pszData != '\0') {
        printf("%p\n", pszData);
        pszData += 1;
        nLength += 1;
    }

    // %lu?
    printf("Length = %d\n", nLength);
    printf("Length = %lu\n", strlen(szBuffer));
    printf("Length = %lu\n", strlen("World"));

}