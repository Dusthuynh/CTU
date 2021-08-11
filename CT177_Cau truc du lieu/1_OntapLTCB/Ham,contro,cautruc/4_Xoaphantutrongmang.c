#include<stdio.h>
void Delete(int p, int a[],int *pn){
    for(int i=p;i<*pn;i++)
        a[i]=a[i+1];
    *pn-=1;
}

int main(){
    int a[] = {1, 5, 20, 0};
    int n =sizeof(a)/sizeof(int);
    int o,p,i;
    p=2;
    for(i=0;i<=n-1;i++)
        printf("%d ",a[i]);
    Delete(p,a, &n);
    printf("\n");
    for(i=0;i<=n-1;i++)
        printf("%d ",a[i]);
}