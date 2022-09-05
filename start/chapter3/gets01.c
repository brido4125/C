//
// Created by 홍창섭 on 2022/08/30.
//

#include <stdio.h>

int main(void){
    char szName[32] = {0};

    printf("이름 입력 :");
    fgets(szName,sizeof(szName),stdin);

    printf("당신의 이름은 ");
    puts(szName);
    puts("입니다.");
    return 0;
}
