#include<stdio.h>
//1.Dem so luong chu so cua mot so nguyen x vd:15962
/*int dem(int x){
    if(x<0) return dem(-x);     //truong hop x am thi tim scs doi cua x
    if (x<10) return 1;
    else return dem(x/10)+1;
}

int main(){
    int x;
    printf("x=");scanf("%d",&x);
    printf("scs=%d",dem(x));
    return 0;
}*/
//---------------------------------------------------------------------//
//2.Chuyen x sang he nhi phan 18=10010
/*
18/9=2 0(b)
n(9)*10+b       10010

1(b)
n(4)*10+b       1001

0(b)
n(2)*10+b       100

0(b)
n(1)*10+b       10

1(b)
n(0)*10+b       1
*/
/*int nhiphan(int x){
    int b;
    if(x==0)
         return 0;
    else
         b=x%2; 
    return nhiphan(x/2)*10+b;
}

int main(){
    int x;
    printf("x=");scanf("%d",&x);
    printf("nhiphan=%d",nhiphan(x));
    return 0;
}*/
//--------------------------------------------------------//
//3.Dao nguoc so x vd: 15962->26951
int daonguoc(int x){
    int b;
    if(x==0) return 0;
    else b=x%10;
    return daonguoc(x/10)+b*10;
}
int main(){
    int x;
    printf("x=");scanf("%d",&x);
    printf("daonguoc=%d",daonguoc(x));
    return 0;
}
