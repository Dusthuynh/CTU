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
void sort(List *pL){
    Position P,Q;
    ElementType temp;
    P=(*pL);
    while (P->Next!=NULL){
        Q=P->Next;
        while(Q->Next!=NULL){
            if (P->Next->Element>Q->Next->Element){
                temp=P->Next->Element;
                P->Next->Element=Q->Next->Element;
                Q->Next->Element=temp;
            }
            Q=Q->Next;
        }
        P=P->Next;
    }
}
int main(){
	List L;
	readList(&L);
	printList(L);
	sort(&L);
	printList(L);
	return 0;
}
