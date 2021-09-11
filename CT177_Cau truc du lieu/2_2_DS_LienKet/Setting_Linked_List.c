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
