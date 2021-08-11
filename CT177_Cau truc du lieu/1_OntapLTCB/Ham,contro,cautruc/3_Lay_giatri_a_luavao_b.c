#include<stdio.h>

int main(){
    void *p;
    int a = 5, b = 2;
    p = &a;
    b=*p;
    printf("%d %d %d", a, b, *((int*)p));
}