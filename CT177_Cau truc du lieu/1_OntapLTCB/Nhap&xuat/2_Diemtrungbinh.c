#include <stdio.h>
int main(){
    char name;
    float lt,th1,th2,th3,th4,TB;
    scanf("%c",&name);
    scanf("%f%f%f%f%f",&lt,&th1,&th2,&th3,&th4);
    TB=(lt+th1+th2+th3+th4)/5;
    printf("%c\n",name);
    printf("Ly thuyet: %.2f\n",lt);
    printf("Thuc hanh 1: %.2f\n",th1);
    printf("Thuc hanh 2: %.2f\n",th2);
    printf("Thuc hanh 3: %.2f\n",th3);
    printf("Thuc hanh 4: %.2f\n",th4);
    printf("Trung binh: %.2f",TB);
}
/*Viết chương trình cho phép nhập vào chữ cái đầu tiên của tên của một sinh viên cùng với điểm cuối kỳ của các bài thi của người đó (gồm bài lý thuyết và 4 bài thực hành). Hiển thị tên người đã nhập với các kết quả thi và điểm trung bình của người đó.
Điểm trung bình được tính bằng tổng điểm lý thuyết và thực hành chia cho 5.
Các kết quả thi và điểm trung bình được hiển thị với 2 số lẻ phần thập phân.
Input	                       
K
9.5 8 7 4.5 9
Result
K 
Ly thuyet: 9.50
Thuc hanh 1: 8.00
Thuc hanh 2: 7.00
Thuc hanh 3: 4.50
Thuc hanh 4: 9.00
Trung binh: 7.60*/
