#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef int ElementType;

struct Node{
	ElementType Element;
	struct Node *Next;
};

typedef struct Node* Position;
typedef Position List;

void makeNullList(List *l){
	(*l)=(struct Node*)malloc(sizeof(struct Node));
	(*l)->Next = NULL;
}

int emptyList(List l){
	return l->Next == NULL;
}

void insertList(ElementType x,Position P,List *pL){
	Position T = (struct Node*)malloc(sizeof(struct Node));
	T->Element=x;
	T->Next = P->Next;
	P->Next = T;
}

void printList(List L){
	while(L->Next!=NULL){
		printf("%d ",L->Next->Element);
		L = L->Next;
	}
}

List endList(List L){
	while(L->Next!=NULL){
		L=L->Next;
	}
	return L;
}

int main(){
	List L;
	makeNullList(&L);
	int x, n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		insertList(x,endList(L),&L);
	}
	
	printList(L);
	
}


