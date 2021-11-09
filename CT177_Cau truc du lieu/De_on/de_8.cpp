#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef int DataType;
struct Node{
	DataType Data;
	struct Node *Right,*Left;
};

typedef struct Node *Tree;

void makeNullTree(Tree *pt){
	(*pt)=NULL;
}

void insertNode(DataType x, Tree *pt){
	if((*pt)==NULL){
		(*pt)=(struct Node*)malloc(sizeof(struct Node));
		(*pt)->Data = x;
		(*pt)->Right = NULL;
		(*pt)->Left = NULL;
	}else{
		if(x > (*pt)->Data)
			insertNode(x,&((*pt)->Right));
		else if(x < (*pt)->Data)
			insertNode(x,&((*pt)->Left));
	}
}

void LNR(Tree T){
	if(T!=NULL){
		LNR(T->Left);
		printf("%d ",(T->Data));
		LNR(T->Right);
	}
}

int checkCP(int x){
	float f  = sqrt(x);
	int i = sqrt(x);
	if ((f-(float)i) == 0)
		return 1;
	else
		return 0;
}

int deleteMax(Tree *pt){
	int k;
	if((*pt)->Right==NULL){
		k = (*pt)->Data;
		(*pt)=(*pt)->Left;
		return k;
	}else
		return deleteMax(&((*pt)->Right));
}

void deleteNode(int x, Tree *pt){
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

void deleteCP(Tree *pt){
	if((*pt)!=NULL)
		deleteCP(&((*pt)->Left));
	while((*pt)!=NULL && checkCP((*pt)->Data))
		deleteNode((*pt)->Data,&(*pt));
	if((*pt)!=NULL)
		deleteCP(&((*pt)->Right));
}

int sumTree(Tree t){
	if(t==NULL) return 0; 
	else if(t->Left==NULL && t->Right==NULL) return t->Data;
	else return (t->Data) + sumTree(t->Left) + sumTree(t->Right);
}

int check2Son(Tree t){
	int sumL = sumTree(t->Left);
	int sumR = sumTree(t->Right);
	if(sumL == sumR)
		return 1;
	else return 0;
}

void findSameSon(Tree t){
	if(t!=NULL)
		findSameSon(t->Right);
	if(t!=NULL)
		if(check2Son(t) && (t->Left!=NULL) && (t->Right!=NULL))
			printf("%d ",t->Data);
	if(t!=NULL)
		findSameSon(t->Left);
}

int main(){
	Tree T;
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		insertNode(x, &T);
	}
	printf("\n 1. ");
	LNR(T);
	
	printf("\n 2. ");
	deleteCP(&T);
	LNR(T);
	
	printf("\n 3. ");
	findSameSon(T);
	
}
