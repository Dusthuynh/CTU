#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef int DataType;
struct Node{
	DataType Data;
	struct Node *Right, *Left;
};

typedef struct Node *Tree;

void makeNullTree(Tree *t){
	(*t)=NULL;
}

void insertNode(DataType x, Tree *t){
	if((*t)==NULL){
		(*t)=(struct Node*)malloc(sizeof(struct Node));
		(*t)->Data = x;
		(*t)->Left = NULL;
		(*t)->Right = NULL;
	}else{
		if(x > (*t)->Data)
			insertNode(x,&((*t)->Right));
		else if(x < (*t)->Data)
			insertNode(x,&((*t)->Left));
	}
}

void LNR(Tree t){
	if(t!=NULL){
		LNR(t->Left);
		printf("%d ",t->Data);
		LNR(t->Right);	
	}
}

int heightTree(Tree t){
	if(t==NULL) return -1;
	else{
		int L = heightTree(t->Left);
		int R = heightTree(t->Right);
		if(L > R) return L+1;
		else return R+1;
	}
}

int main(){
	Tree T;
	makeNullTree(&T);
	int n, x;
	printf("\n 1. ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		insertNode(x, &T);
	}
	
	printf("\n 2. ");
	LNR(T);
	
	printf("\n 3. %d",heightTree(T));
}
