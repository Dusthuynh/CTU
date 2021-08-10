#include <stdio.h>
//tinh UCLN va BCNN cua 2 so a va b
int UCLN(int x,int y){  //mac dinh la x>y, neu y>x thi doi 2 so lai 
    if (y==0) return x;
    else return UCLN(y,x%y);
}

int BCNN(int x,int y){
    return (x*y)/UCLN(x,y);
}

int main(){
    int a,b;
    printf("a,b=");
    scanf("%d%d",&a,&b);
    printf("UCLN cua a va b: %d",UCLN(a,b));
    printf("\nBCNN cua a va b: %d",BCNN(a,b));
return 0;
}