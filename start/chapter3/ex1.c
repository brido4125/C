//
// Created by 홍창섭 on 2022/09/05.
//

#include <stdio.h>

int main(void){
    int age = 0;
    char name[32] = {0};

    printf("나이를 입력하세요 : ");
    scanf("%d%*c", &age);

    printf("이름을 입력하세요 : ");
    gets(name);
    //fgets(name, sizeof(name), stdin);

    printf("나이는 %d이고 이름은 %s입니다. \n",age,name);
    return 0;
}