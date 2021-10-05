#include<stdio.h>


typedef int ElementType;

struct Node{
    ElementType Element;
    struct Node *Next;
};

typedef struct Node *Position;
typedef Position List;

void makenullList(List *L){
    (*L)=(struct Node*)malloc(sizeof(struct Node));
    (*L)->Next=NULL;
}

List makenullList1(){
    List *L;
    (*L)=(struct Node*)malloc(sizeof(struct Node));
    (*L)->Next=NULL;
    return L;
}

Position first(List L){
    return L;
}

Position endList(List L){
    Position p = L;
    while(p->Next!=NULL){
        p=p->Next;
    }
    return p;
}

ElementType retrieve(Position P, List L){
    if(P->Next!=NULL)
        return P->Next->Element;
}

Position next(Position P, List L){
    return P->Next;
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
    Position p = L;
    return p->Next==NULL;
}

void readList(List *L){
    Position P = first(*L);
    int n,x;
    printf("Nhap so luong danh sach: ");scanf("%d",&(n));
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        insertList(x,P,&L);
        P=P->Next;
    }
}

void printList(List L){
    Position P=first(L);
    while(P->Next!=NULL){
        printf("%d",retrieve(P,L));
        P=P->Next;
    }
}

void insertList(ElementType X,Position P,List *L){
    Position T = (struct Node *)malloc(sizeof(struct Node));
    T->Element=X;
    T->Next=P->Next;
    P->Next=T;
}

void Delete_List(Position P, List *L){
    Position T;
    if (P->Next!=NULL){
       T=P->Next;
       P->Next=T->Next;
       free(T);
    }
}

void Delete_duplicate(List *L){
   
}

void swap(Position a, Position b, List *L){

}

void Sort_List(List *L){

}
