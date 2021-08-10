#include<stdio.h>
//tinh x!
long giaithua(int x){
    if(x<=0) return 1;
    else return x*giaithua(x-1);
}

int main(){
    int x;
    printf("x=");
    scanf("%d",&x);
    printf("%d!=%d",x,giaithua(x));
    return 0;
}