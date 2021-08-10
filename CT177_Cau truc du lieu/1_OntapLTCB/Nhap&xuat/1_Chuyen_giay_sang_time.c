/*Viết chương trình chuyển đổi số giây cho trước thành dạng giờ/phút/giây, e.g.: 13806 = 03h50m06s.
For example:
Input	Result
3661   01:01:01
18779  05:12:59*/
#include <stdio.h>
int main(){
    int x,h,m,s;
    scanf("%d",&x);
    h=x/3600;
    m=(x-h*3600)/60;
    s=(x-h*3600-m*60);
    printf("%.2d:%.2d:%.2d",h,m,s);
}