#include <stdio.h>
#define MaxLength 100

typedef int ElementType;
typedef struct{
    ElementType Elements[MaxLength];
    int Front, Rear;
}Queue;

Queue Q;

void makenullQueue(Queue *pQ){
    pQ->Front=-1;
    pQ->Rear=-1;
}

int emptyQueue(Queue Q){
    return Q.Front==-1;
}

int fullQueue(Queue Q){                        //!!important
    return (Q.Rear-Q.Front+1)%MaxLength==0;
}

ElementType front(Queue Q){
    if (emptyQueue(Q))
        printf("Hang rong");
    else
        return Q.Elements[Q.Front];
}

void deQueue(Queue *pQ){
    if(!emptyQueue(*pQ)){
        if(pQ->Front==pQ->Rear)
            makenullQueue(pQ);
        else
            pQ->Front=(pQ->Front+1)%MaxLength;
    }else printf("Loi: Hang rong!!!");
}

void enQueue(ElementType x, Queue *pQ){
    if(!fullQueue(*pQ)){
        if(emptyQueue(*pQ)) pQ->Front=0;
        pQ->Rear=(pQ->Rear+1)%MaxLength;
        pQ->Elements[pQ->Rear]=x;
    }
    else printf("Loi: Hang day!");
}

