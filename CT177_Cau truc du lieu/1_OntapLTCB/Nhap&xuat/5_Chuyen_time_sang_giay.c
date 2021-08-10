/*Viết chương trình cho phép nhập vào giờ, phút, giây và chuyển chúng sang số giây tương ứng, e.g: 3h5m6s = 3*3600 + 5*60 + 6.
Input	      Result
1h1m1s      So giay: 3661
*/
#include<stdio.h>
int main(){
    int h,m,s;
    scanf("%dh%dm%ds",&h,&m,&s);
    printf("So giay: %d",h*3600+m*60+s);
}