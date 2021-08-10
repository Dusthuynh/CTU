#include<stdio.h>
//tinh tong cac so tu 1 den n

int tong(int x){
    int res;
    if(x==1) return 1;
    else res=x+tong(x-1);
    return res;
}

int main(){
    int n;
    printf("n=");
    scanf("%d",&n);
    printf("Tong tu 1 den n= %d",tong(n));
}

/*t5=5+_t4      15
t4=4+t3         10
t3=3+t2         6
t2=2+t1         3
t1=1 */
