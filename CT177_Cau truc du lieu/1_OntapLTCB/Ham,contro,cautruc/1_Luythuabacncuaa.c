/*Viết hàm đệ quy tính luỹ thừa bậc n của a:*/
#include<stdio.h>
double power(float a,int n){
    if(n==0) return 1;
    else return a*power(a,n-1);
}
int main(){
    printf("%.4f\n", power(2, 3));
}