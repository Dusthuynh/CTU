#include<stdio.h>
#define MaxLength 300

typedef int ElementType;
typedef int Position;
typedef struct{
    ElementType Elements[MaxLength];
    Position Last;
} List;

List L;

Position first(List L){
    return 1;
}

Position endList(List L){
    return L.Last+1;
}

ElementType retrieve(Position P, List L){
    return L.Elements[P-1];
}

Position next(Position P, List L){
    return P+1;
}

Position locate(ElementType X, List L){
    Position P = first(L);
    int Found = 0;
    while((P != endList(L)) && (Found == 0 )){
        if(retrieve(P,L) == X) Found==1;
        else P = next(P, L);
    }
    return P;
}

int emptyList(List L){
    return L.Last==0;
}

int fullList(List L){
    return L.Last==MaxLength;
}

void MakeNull_List(List *L){
    L->Last=0;
}

void Read_List(List *L){
    Position P = first(*L);
    printf("Nhap so luong danh sach: ");scanf("%d",&(L->Last));
    printf("Roi nhap di\n");
    while(P!=endList(*L)){
        scanf("%d", &(L->Elements[P-1]));
        P=next(P,*L);
    }
}

void Print_List(List L){
    Position P=first(L);
    while (P != endList(L)){
        printf("%d ", L.Elements[P-1]);
        P=next(P,L);
    }
    printf("\n");
}

void Insert_List(ElementType X,Position P,List *L){
    if(fullList(*L))
        printf("Danh sach day\n");
    else if ((P<1) || (P>endList(*L)))
        printf("Vi tri khong hop le\n");
    else {
        Position Q;
        for(Q=L->Last; Q>P-1; Q--){
            L->Elements[Q]=L->Elements[Q-1];
        }
        L->Last++;
        L->Elements[P-1]=X;
    }
}

void Delete_List(Position P, List *L){
    if (emptyList(*L))
        printf("Danh sach rong!\n");
    else if((P<1) || (P>L->Last))
        printf("Vi tri khong hop le\n");
    else{
        Position Q;
        for(Q=P-1;Q<L->Last-1;Q++)
            L->Elements[Q]=L->Elements[Q+1];
        L->Last--;
    }
}

int main(){
    ElementType X;
    Position P;
    MakeNull_List(&L);
    Read_List(&L);
    printf("Danh sach vua nhap: ");
    Print_List(L); // In danh sach len man hinh
    printf("Phan tu can them: ");scanf("%d",&X);
    printf("Vi tri can them: ");scanf("%d",&P);
    Insert_List(X,P,&L);
    printf("Danh sach sau khi them phan tu la: ");
    Print_List(L);
    printf("Noi dung phan tu can xoa: ");scanf("%d",&X);
    P=locate(X,L);
    Delete_List(P,&L);
    printf("Danh sach sau khi xoa %d la: ",X);
    Print_List(L);
    return 0;
}
