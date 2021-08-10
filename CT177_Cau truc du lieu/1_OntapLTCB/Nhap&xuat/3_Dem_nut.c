#include<stdio.h>

int main(){
    int x,res=0,temp;
    scanf("%d",&x);
    for(int i=0;i<3;i++){
        temp=x%10;
        res+=temp;
        x/=10;
    }
    printf("%d",(res+x)%10);
}
/*Viết chương trình nhập vào số xe (4 chữ số). Tính xem số xe này có bao nhiêu nút, hiển thị số nút ra màn hình. Biết số xe có dạng abcd thì số nút = (a+b+c+d) % 10. Dữ liệu đầu vào xem như hợp lệ, không cần kiểm tra.*/

