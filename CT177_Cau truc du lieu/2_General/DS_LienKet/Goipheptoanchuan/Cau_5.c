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
float getAvg(List L){
    Position P=L;
    if (P->Next==NULL)
        return -10000.000;
    else {
        float S=0;
        int count=0;
        while (P->Next!=NULL){
            S += P->Next->Element;
            P=P->Next;
            count++;
        }
        return S/count;
    }
}
int main(){
	List L;
	readList(&L);
	printList(L);
	printf("%.3f", getAvg(L));
	return 0;
}
