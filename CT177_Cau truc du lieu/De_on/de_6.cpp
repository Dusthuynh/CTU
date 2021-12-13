#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef int DataType;
struct Node{
	DataType Data;
	struct Node *Left, *Right;
};
typedef struct Node *Tree;

void makeNullTree(Tree *pt){
	(*pt)=NULL;
}

void insertNode(int x, Tree *pt){
	if((*pt)==NULL){
		(*pt)=(struct Node*)malloc(sizeof(struct Node));
		(*pt)->Data=x;
		(*pt)->Left=NULL;
		(*pt)->Right=NULL;
	}else{
		if(x > (*pt)->Data)
			insertNode(x, &((*pt)->Right));
		else if(x < (*pt)->Data)
			insertNode(x, &((*pt)->Left));
	}
}

void LNR(Tree t){
	if(t!=NULL){
		LNR(t->Left);
		printf("%d ",t->Data);
		LNR(t->Right);
	}
}

int deleteMax(Tree *t){
	int k;
	if((*t)->Right==NULL){
		k=(*t)->Data;
		(*t)=(*t)->Left;
		return k;
	}else
		deleteMax(&((*t)->Right));
}

void deleteNode(Tree *pt){
	if((*pt)->Left==NULL && (*pt)->Right==NULL)
		(*pt)=NULL;
	else{
		if((*pt)->Left==NULL)
			(*pt)=(*pt)->Right;
		else if((*pt)->Right==NULL)
			(*pt)=(*pt)->Left;
		else
			(*pt)->Data = deleteMax(&((*pt)->Left));
	}
}

int checkSNT(int x){
	if(x<2) return 0;
	for(int i=2; i<=sqrt(x); i++){
			if(x%i == 0) return 0;
	}
	return 1;
}

void deleteSNT(Tree *t){
	if((*t)!=NULL)
		deleteSNT(&(*t)->Left);
	while((*t)!=NULL && checkSNT((*t)->Data)){
		deleteNode(&(*t));
	}
	if((*t)!=NULL)
		deleteSNT(&(*t)->Right);
}

int countNode(Tree t){
	if(t==NULL) return 0;
	else return 1 + countNode(t->Left) + countNode(t->Right);
}

int checkSonEqual(Tree t){
	int L = countNode((t->Left));
	int R = countNode((t->Right));
	if(L == R)
		return 1;
	else return 0;
}

void findNodeEqual(Tree t){
	if(t!=NULL)
		findNodeEqual((t->Left));
	if(t!=NULL)
		if(checkSonEqual(t) && (t->Left!=NULL) && (t->Right!=NULL))
		printf("%d ",t->Data);
	if(t!=NULL)
		findNodeEqual((t->Right));
}

int main(){
	Tree T;
	makeNullTree(&T);
	int x, n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		insertNode(x, &T);
	}
	printf("\n 1. ");
	LNR(T);
	
	printf("\n 3. ");
	findNodeEqual(T);
	
	deleteSNT(&T);
	printf("\n 2. ");
	LNR(T);
	

}
