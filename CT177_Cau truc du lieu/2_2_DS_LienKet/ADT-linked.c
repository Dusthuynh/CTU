#include<stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct Node{
    ElementType Element;
    struct Node* Next;
};
typedef struct Node* Position;      //con trỏ chứa địa chỉ
typedef Position List;

void makenullList (List *L){
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

Position next(Position P, List L){
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
    while (next(P,L) != NULL && count <i){
        if (retrieve(P,L) == X)
            count++;
        if(count<i)
            P=next(P,L);
    }
    return P;
}

Position previous(Position P, List L){
    Position T = first(L);
    while (next(T,L) != P) T=next(T,L);
    return T;
}

void printList (List L){
    Position P =first(L);
    while( P!=endList(L)){
        printf("%d ", retrieve(P,L));
        P = next(P,L);
    }
    printf("\n");
}

void readList (List *L){
    int n, value;
    printf("Nhap so phan tu trong danh sach: ");scanf("%d",&n);
    Position P = first(*L);
    
    printf("roi nhap di: ");
    for(int i=0; i< n; ++i){     
        scanf("%d",&value);
        insertList (value, P, L);
        P = next(P,*L);
    }
}

int main(){
    ElementType X;
    Position P;
    List L;
    makenullList(&L);
    readList(&L);
    printf("Danh sach vua nhap: ");
    printList(L); 
    printf("Phan tu can them: ");scanf("%d",&X);        //cach viet ham main
    insertList(X,P,&L);
    printf("Danh sach sau khi them phan tu la: ");
    printList(L);
    printf("Noi dung phan tu can xoa: ");scanf("%d",&X);
    P = locate(X,L);
    deleteList(P,&L);
    printf("Danh sach sau khi xoa %d la: ",X);
    printList(L);

    /*printf("Danh sach sau khi xoa trung lap la: ");
    deleteduplicate(&L);
    printList(L);*/
    return 0;
}