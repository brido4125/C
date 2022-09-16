#include <stdio.h>

typedef struct Point{
    int x;
    int y;
}point;

int main() {
    int x = 10;
    int *y = &x;
    printf("x의 주소값 : %p\n", &x);
    printf("포인터 y의 주소값 = %p\n", y);
    printf("포인터 y가 가지는 값 = %d\n", *y);

    point p1 = {.x = 12,.y = 34};
    printf("p1의 주소 = %p\n", &p1);
    printf("p1의 X값 = %d, y값 = %d\n", p1.x,p1.y);
    point *P = &p1;
    printf("포인터의 P의 주소 = %p\n", P);
    printf("포인터 P의 X값 = %d, y값 = %d\n", P->x,P->y);
    return 0;
}
