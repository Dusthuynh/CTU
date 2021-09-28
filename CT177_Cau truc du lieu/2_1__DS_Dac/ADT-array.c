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
        if(retrieve(P,L) == X) Found = 1;
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

void makenullList(List *L){
    L->Last=0; 
}

void readList(List *L){
    Position P = first(*L);
    printf("Nhap so luong danh sach: ");scanf("%d",&(L->Last));
    printf("Xin nhap:\n");
    while(P!=endList(*L)){
        scanf("%d", &(L->Elements[P-1]));
        P=next(P,*L);
    }
}

void printList(List L){
    Position P=first(L);
    while (P != endList(L)){
        printf("%d ", L.Elements[P-1]);
        P=next(P,L);
    }
    printf("\n");
}

void insertList(ElementType X,Position P,List *L){
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

void deleteList(Position P, List *L){
    if (emptyList(*L))
        printf("Danh sach rong!\n");
    else if((P<1) || (P>L->Last))
        printf("Vi tri khong hop le\n");
    else{
        Position Q;
        for(Q=P-1;Q<(L->Last-1);Q++)
            L->Elements[Q]=L->Elements[Q+1];
        L->Last--;
    }
}

void deleteDuplicate(List *L){
    int  P = first(*L) - 1;
    int  Q;
    while (P != L->Last-1){
        Q = P + 1;
        while (Q != L->Last){
            if(L->Elements[P] == L->Elements[Q])
                deleteList(Q+1,L);
            else
                Q++;
        }
        P++;
    }
}

void swap(Position a, Position b, List *L){
     ElementType temp;
     temp=L->Elements[a-1];
     L->Elements[a-1]=L->Elements[b-1];
     L->Elements[b-1]=temp;
}

void sortList(List *L){
     Position P=first(*L);
     while (P!=endList(*L)){
           Position Q=next(P,*L);
           while (Q!=endList(*L)){
                 if (retrieve(P,*L)>retrieve(Q,*L))
                    swap(P,Q,L);
                 Q=next(Q,*L);
                 }
           P=next(P,*L);
     }
}

int main(){
    ElementType X;
    Position P;
    makenullList(&L);
    readList(&L);
    printf("Danh sach vua nhap: ");
    printList(L); // In danh sach len man hinh

    printf("Phan tu can them: ");scanf("%d",&X);
    printf("Vi tri can them: ");scanf("%d",&P);
    insertList(X,P,&L);
    printf("Danh sach sau khi them phan tu la: ");
    printList(L);

    printf("Noi dung phan tu can xoa: ");scanf("%d",&X);
    P = locate(X,L);
    deleteList(P,&L);
    printf("Danh sach sau khi xoa %d la: ",X);
    printList(L);

    printf("Danh sach sau khi xoa trung lap la: ");
    deleteDuplicate(&L);
    printList(L);

    printf("Danh sach sau khi sap xep tang dan la: ");
    sortList(&L);
    printList(L);
    return 0;
}
