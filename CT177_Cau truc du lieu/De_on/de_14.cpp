#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef int DataType;

struct Node{
	DataType Data;
	struct Node *Left,*Right;
};

typedef struct Node *Tree;

void makeNullTree(Tree *t){
	(*t)=NULL;
}

void insertNode(int x, Tree *t){
	if((*t)==NULL){
		(*t)=(struct Node*)malloc(sizeof(struct Node));
		(*t)->Data = x;
		(*t)->Left = NULL;
		(*t)->Right = NULL;
	}else{
		if((*t)->Data > x)
			insertNode(x,&((*t)->Left));
		else if((*t)->Data < x)
			insertNode(x,&((*t)->Right));
	}
}

void RLN(Tree t){
	if(t!=NULL){
		RLN(t->Right);
		RLN(t->Left);
		printf("%d ",t->Data);	
	}
}

int findMin(Tree t){
	while(t->Left!=NULL){
		t = t->Left;
	}
	return t->Data;
}

int main(){
	Tree t;
	makeNullTree(&t);
	int x, n;
	printf("\n 1. ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		insertNode(x,&t);
	}
	
	printf("\n 2. ");
	RLN(t);
	
	printf("\n 3. MIN = %d",findMin(t));
}
