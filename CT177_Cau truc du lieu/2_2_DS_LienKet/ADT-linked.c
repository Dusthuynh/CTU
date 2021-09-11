#include<stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct Node{
    ElementType Element;
    struct Node* Next;
};
typedef struct Node* Position;      //con trỏ chứa địa chỉ
typedef Position List;

void MakeNull_List (List *L){
    (*L)=(struct Node*)malloc(sizeof(struct Node));
    (*L)->Next=NULL;
}

int emptyList (List L){
    return (L->Next==NULL);
}

ElementType retrieve(Position P, List L){
    if(P->Next != NULL)
        return P->Next->Element;
}

void insertList (ElementType X, Position P, List *L){
    Position T;
    T=(struct Node*)malloc(sizeof(struct Node));
    T->Element=X;
    T->Next=P->Next;
    P->Next=T;
}

void deleteList (Position P, List *L){
    Position T;
    if(P->Next==NULL){
        T=P->Next;
        P->Next=T->Next;
        free(T);
    }
}

Position first(List L){
    return L;
}

Position endList(List L){
    Position P;
    P=first(L);
    while (P->Next != NULL)
        P=P->Next;
    return P;
}

Position Next(Position P, List L){
    return P->Next;
}

Position locate(ElementType X, List L){
    Position P;
    P=first(L);
    while (P->Next != NULL){
        if(X == P->Element) 
            return P;
        else P = P->Next;
    }
    return P;
}

Position myLocate(ElementType X, int i, List L){
    Position P = first(L);
    int count = 0;
    while (Next(P,L) != NULL && count <i){
        if (retrieve(P,L) == X)
            count++;
        if(count<i)
            P=Next(P,L);
    }
    return P;
}

Position Previous(Position P, List L){
    Position T = first(L);
    while (Next(T,L) != P) T=Next(T,L);
    return T;
}

void Print_List (List L){
    Position P =first(L);
    while( P!=endList(L)){
        printf("%d ", retrieve(P,L));
        P = Next(P,L);
    }
    printf("\n");
}

void Read_List (List *L){
    int n, value;
    printf("Nhap so phan tu trong danh sach: ");scanf("%d",&n);
    Position P = first(*L);
    
    printf("roi nhap di: ");
    for(int i=0; i< n; ++i){     
        scanf("%d",&value);
        insertList (value, P, L);
        P = Next(P,*L);
    }
}

int main(){
    ElementType X;
    Position P;
    List L;
    MakeNull_List(&L);
    Read_List(&L);
    printf("Danh sach vua nhap: ");
    Print_List(L); // In danh sach len man hinh
    printf("Phan tu can them: ");scanf("%d",&X);
    printf("Vi tri can them: ");scanf("%d",&P);
    insertList(X,P,&L);
    printf("Danh sach sau khi them phan tu la: ");
    Print_List(L);
   /* printf("Noi dung phan tu can xoa: ");scanf("%d",&X);
    P = Locate(X,L);
    Delete_List(P,&L);
    printf("Danh sach sau khi xoa %d la: ",X);
    Print_List(L);
    printf("Danh sach sau khi xoa trung lap la: ");
    Delete_duplicate(&L);
    Print_List(L);*/
    return 0;
}