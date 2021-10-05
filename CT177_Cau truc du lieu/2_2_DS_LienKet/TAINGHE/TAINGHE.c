#include <stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
    char maTaiNghe[10];
    char tenTaiNghe[50];
    char nuocSX[20];
    int donGia;
    int soLuong;
    int thanhTien;
}ElementType;

struct Node{
    ElementType Element;
    struct Node *Next;
};

typedef struct Node *Position;
typedef Position List;

void makenullList(List *L){
    (*L) = (struct Node*)malloc(sizeof(struct Node));
    (*L)->Next=NULL;
}

Position first(List L){
    return L;
}

Position endList(List L){
    Position p = L;
    while(p->Next==NULL)
        p=p->Next;
    return p;
}

void insertList(ElementType X,Position p,List *L){
    Position k = (struct Node*)malloc(sizeof(struct Node));
    k -> Element=X;
    k->Next=p->Next;
    p->Next=k;
}

ElementType nhap1LoaiTN(){
    ElementType p;
    char c;
    scanf("%c",&c);
    printf("Nhap ma tai nghe: ");
    fgets(p.maTaiNghe,10,stdin);
    p.maTaiNghe[strlen(p.maTaiNghe)-1]='\0';
    printf("Nhap ten tai nghe: ");
    fgets(p.tenTaiNghe,50,stdin);
    p.tenTaiNghe[strlen(p.tenTaiNghe)-1]='\0';
    printf("Nhap nuoc SX: ");
    fgets(p.nuocSX,20,stdin);
    p.nuocSX[strlen(p.nuocSX)-1]='\0';
    printf("Nhap don gia: ");
    scanf("%d",&p.donGia);
    printf("Nhap so luong tai nghe: ");
    scanf("%d",&p.soLuong);
    p.thanhTien=p.donGia*p.soLuong;
    return p;
}

void printList(List L){
    Position p = L;
    while(p->Next!=NULL){
        printf("*Ma: %s; Ten: %s; Nuoc SX: %s; Don gia: %d; So luong: %d; Thanh tien: %d\n",p->Next->Element.maTaiNghe,p->Next->Element.tenTaiNghe,p->Next->Element.nuocSX,p->Next->Element.donGia,p->Next->Element.soLuong,p->Next->Element.thanhTien);
        p=p->Next;
    }
}

void in1LoaiTN(ElementType x){
    printf("Ma: %s; Ten: %s; Nuoc SX: %s; Don gia: %d; So luong: %d; Thanh tien: %d\n",x.maTaiNghe,x.tenTaiNghe,x.nuocSX,x.donGia,x.soLuong,x.thanhTien);
}

Position locate(char ten[],List L){
    Position p = L;
    while(p->Next!=NULL){
        if(strcmp(ten,p->Next->Element.tenTaiNghe)==0){
            break;
        }else p=p->Next;
    }
    return p;
}

int main(){
    List TAINGHE;
    int n;
    //---------1---------//
    printf("Nhap so loai tai nghe can quan ly:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("*Nhap thong tin tai nghe thu %d\n",(i+1));
        ElementType x = nhap1LoaiTN();
        insertList(x,endList(TAINGHE),&TAINGHE);
    }
    printf("\n");

    //---------2---------//
    printf("Thong tin DS tai nghe da nhap:\n");
    printList(TAINGHE);
    printf("\n");

    //---------3---------//
    char ten[30];
    printf("Nhap ten tai nghe can tim kiem: ");
    fgets(ten,30,stdin);
    ten[strlen(ten)-1]='\0';
    int check=0;
   /* Position p = locate(ten,TAINGHE);
    if(p->Next==NULL)
        printf("khong tim thay tai nghe");
    else{
        printf("Thong tin tai nghe can tim:\n");
        in1LoaiTN(p->Next->Element);
    }*/

    //---------4---------//

    return 0;
}