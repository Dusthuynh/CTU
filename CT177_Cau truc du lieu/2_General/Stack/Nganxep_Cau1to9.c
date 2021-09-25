//Cau_1
#define MaxLength 100
typedef struct {
     int DuLieu[MaxLength];
     int Dinh;
} NganXep;

//Cau_2
void khoitao(NganXep *pS){
    pS->Dinh=SoPhanTu;
}

//Cau_3
int ktRong(NganXep S){
    return S.Dinh==SoPhanTu;
}

//Cau_4
int ktDay(NganXep S){
    return (S.Dinh==0);
}

//Cau_5
void them(int X, NganXep *pS){
    if(pS->Dinh!=0){
        pS->Dinh--;
        pS->DuLieu[pS->Dinh]=X;
    }
}

//Cau_6
void xoa(NganXep *pS){
    if(pS->Dinh!=SoPhanTu)
        pS->Dinh++;
}

//Cau_7
int giatriDinh(NganXep S){
    if(S.Dinh!=SoPhanTu)
        return S.DuLieu[S.Dinh];
    else {
        printf("Loi, hang rong\n");
        return -1;
    }    
}

//Cau_8
void hienthi(NganXep *pS){
    while(!ktRong(*pS)){
        printf("%d ",giatriDinh(*pS));
        xoa(pS);
    }
}

//Cau_9
void hienthi(NganXep *pS){
    while(!ktRong(*pS)){
            printf("%d ", giatriDinh(*pS));
            xoa(pS);
        }
    printf("\n");
}
void doiNhiPhan(int n, NganXep *pS){
    khoitao(pS);
    while(n!=0){
        them(n%2,pS);
        n/=2;
    }
    hienthi(pS);
}
