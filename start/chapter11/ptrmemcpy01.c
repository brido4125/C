//
// Created by 홍창섭 on 2022/10/23.
//

#include <stdio.h>
#include <string.h>

int main(void){
    char szBuffer[12] = {"HelloWorld"};
    char szNewBuffer[12] = {0};

    //szNewBuffer = szBuffer => 컴파일 에러 발생

    memcpy(szNewBuffer,szBuffer,4);
    puts(szNewBuffer);

    memcpy(szNewBuffer,szBuffer,6);
    puts(szNewBuffer);

    memcpy(szNewBuffer,szBuffer,sizeof(szBuffer));
    puts(szNewBuffer);

    return 0;
}