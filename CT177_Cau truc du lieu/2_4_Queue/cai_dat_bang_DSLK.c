#include <stdio.h>

typedef int ElementType;
struct Node{
    ElementType Element;
    struct Node* Next;
};
typedef struct Node* Position;
typedef struct{
    Position Front, Rear;
}Queue;

void makenullQueue (Queue *pQ){
    Position Header;
    Header = (struct Node*)malloc(sizeof(struct Node));
    Header->Next=NULL;
    pQ->Front=Header;
    pQ->Rear=Header;
}

int emptyQueue(Queue Q){
    return (Q.Front==Q.Rear);
}

ElementType Front(Queue Q){
    return Q.Front->Next->Element;
}

void enQueue(ElementType x, Queue *pQ){
    pQ->Rear->Next=(struct Node*)malloc(sizeof(struct Node));
    pQ->Rear=pQ->Rear->Next;
    pQ->Rear->Element=x;
    pQ->Rear->Next==NULL;
}

void deQueue(Queue *pQ){
    if(!emptyQueue(*pQ)){
        Position T;
        T=pQ->Front;
        pQ->Front=pQ->Front->Next;
        free(T);
    }else printf("Loi : Hang rong");
}