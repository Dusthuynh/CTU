#include<stdio.h>
int is_leap_year(int n){
    if((n%4==0 && n%100!=0) || (n%400==0)) return 1;
    else return 0;
}

int main(){
    if(is_leap_year(1992)) printf("%d la nam nhuan",1992);
    else printf("%d khong la nam nhuan",1992);
}