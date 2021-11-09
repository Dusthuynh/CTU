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
void printOddNumbers(List L){
    Position P=L;
    while (P->Next!=NULL){
        if (P->Next->Element%2!=0)
            printf("%d ", P->Next->Element);
        P=P->Next;
    }
    printf("\n");
}
void copyEvenNumbers(List L1, List *pL){
    makenullList(pL);
    Position P=L1;
    while (P->Next!=NULL){
        if(P->Next->Element%2==0)
            append(P->Next->Element,pL);
        P=P->Next;
    }
}
int main(){
	List L1, L2;
	readList(&L1);
	printList(L1);
	printOddNumbers(L1);
	copyEvenNumbers(L1,&L2);
	printList(L2);
	return 0;
}
