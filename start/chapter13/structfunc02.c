//
// Created by 홍창섭 on 2022/10/24.
//

#include <stdio.h>

typedef struct USERDATA {
    int nAge;
    char szName[32];
    char szPhone[32];
} USERDATA;

void GetUserData(USERDATA *pUser){
    printf("pUser = %p\n", pUser);
    printf("&pUser = %p\n", &pUser);
    printf("nage = %d\n", pUser->nAge);
    pUser->nAge = 100;
    printf("nage = %d\n", pUser->nAge);
    printf("nage = %p\n", &pUser->nAge);
    //scanf("%d%*c", pUser->nAge);
    //gets(pUser->szName);
    //gets(pUser->szPhone);
}

int main(void){
    USERDATA user = {0};
    printf("&user = %p\n", &user);
    GetUserData(&user);
}