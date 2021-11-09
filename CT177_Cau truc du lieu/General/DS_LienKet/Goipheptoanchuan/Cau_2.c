#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElementType;
struct Node
{
	ElementType Element;
	struct Node* Next;
};
typedef struct Node* Position;
typedef Position List;

void makenullList(List *pL){
    (*pL)=(struct Node*)malloc(sizeof(struct Node));
    (*pL)->Next=NULL;
}
void append(ElementType X, List *pL){
    Position P=(*pL);
    while (P->Next!=NULL)
        P=P->Next;
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
	t->Element=X;
	t->Next=P->Next;
	P->Next=t;    
}
void readList(List *pL){
    int n;
    ElementType X;
    scanf("%d", &n);
    makenullList(pL);
    for(int i=1; i<=n; i++){
        scanf("%d", &X);
        append(X,pL);
    }
}
void printList(List L){
	Position P=L;
	while (P->Next!=NULL){
		printf("%d ",P->Next->Element);
		P=P->Next;
	}
	printf("\n");
}
void deleteList(Position p, List *pL)
{
	if (p->Next!=NULL)		
	{
		Position t=p->Next;
		p->Next = t->Next;
		free(t);
	}
}

Position locate(ElementType x, List L)
{
	int Found=0;
	Position p=L;
	while(p->Next!=NULL && !Found)
		if (x==p->Next->Element) Found=1;
		else p=p->Next;
		
	return p;		
}
void erase(ElementType X, List *pL){
    Position P=locate(X,*pL);
    if (P->Next!=NULL)
        deleteList(P, pL);
    else
        printf("Not found %d\n",X);
}
int main(){
	List L;
	ElementType X;
	readList(&L);
	printList(L);
	scanf("%d",&X);
	erase(X,&L);
	printList(L);
	return 0;	
}
