#include <stdio.h>
#include <string.h>
#define Maxlength 40

typedef int Position;
typedef struct{
    char MSSV[10];
    char HoTen[50];
    float DLT,DTH1,DTH2;
}SinhVien;

typedef struct{
    SinhVien A[Maxlength];
    Position n;
}DanhSach;

void makeNullList(DanhSach *pL){
    pL->n=0;
}

void readList(DanhSach *L){
    char c;
    for(int i=0; i<L->n; i++){
        scanf("%c",&c);
    //    printf("mssv");
        fgets(L->A[i].MSSV,10,stdin);
        L->A[i].MSSV[strlen( L->A[i].MSSV)-1] = '\0';

    //    printf("name");
        fgets(L->A[i].HoTen,50,stdin);
        L->A[i].HoTen[strlen( L->A[i].HoTen)-1] = '\0';
        
    //   printf("diem");
        scanf("%f %f %f",&(L->A[i].DLT),&(L->A[i].DTH1),&(L->A[i].DTH2));
    }
}

void printList(DanhSach L){
    for(int i=0; i<L.n; i++)
        printf("%s - %s - %.2f - %.2f - %.2f\n",(L.A[i].MSSV),(L.A[i].HoTen),(L.A[i].DLT),(L.A[i].DTH1),(L.A[i].DTH2));
}

void printSVDat(DanhSach L){
    float DiemS;
    for(int i=0; i<L.n; i++){
        DiemS=(L.A[i].DLT)+(L.A[i].DTH1)+(L.A[i].DTH2);
        if(DiemS>=4)
            printf("%s - %s - %.2f - %.2f - %.2f\n",(L.A[i].MSSV),(L.A[i].HoTen),(L.A[i].DLT),(L.A[i].DTH1),(L.A[i].DTH2));
    }
}

int main(){
    DanhSach SV;
    makeNullList(&SV);
   // printf("Nhap so luong:");
    scanf("%d",&(SV.n));
  //  printf("Nhap thong tin:\n");
    readList(&SV);
  //  printf("In thong tin:\n");
    printList(SV);
    printf("Sinh vien DAT\n");
    printSVDat(SV);
}