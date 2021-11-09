#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef int TypeData;

struct Node{
	TypeData Data;
	struct Node *Right, *Left;
};

typedef struct Node *Tree;

void makeNullTree(Tree *pT){
	(*pT)=NULL;
}

void insertNode(int x, Tree *pt){
	if((*pt)==NULL){
		(*pt)=(struct Node*)malloc(sizeof(struct Node));
		(*pt)->Data=x;
		(*pt)->Right=NULL;
		(*pt)->Left=NULL;
	}else{
		if(x > (*pt)->Data)	insertNode(x,&((*pt)->Right));
		else 
			if(x < (*pt)->Data)	insertNode(x,&((*pt)->Left));
	}
}

void RNL(Tree T){
	if(T!=NULL){
		RNL(T->Right);
		printf("%d ",T->Data);
		RNL(T->Left);
	}
}

int countLeafNode(Tree T){
	if (T==NULL) return 0;
	if(T->Right==NULL && T->Left==NULL)	return 1;
	else return countLeafNode(T->Right) + countLeafNode(T->Left);
}

int checkSNT(int x){
    if (x<2) return 0;
    for (int i=2; i<=sqrt(x); i++){
        if (x%i == 0) return 0;
    }
    return 1;
}

int deleteMin(Tree *pt){
	int k;
	if((*pt)->Left==NULL){
		k = (*pt)->Data;
		(*pt) = (*pt)->Right;
		return k;
	}else
		return deleteMin(&((*pt)->Left));
}

void deleteNode(Tree *pt){
	if(((*pt)->Left==NULL)&&((*pt)->Right==NULL))
		(*pt)=NULL;
	else if((*pt)->Left==NULL)
		(*pt)=(*pt)->Right;
	else if((*pt)->Right==NULL)
		(*pt)=(*pt)->Left;
	else
		(*pt)->Data = deleteMin(&(*pt)->Right);
}

void deleteSNT(Tree *pt){
	if((*pt)!=NULL)
		deleteSNT(&((*pt)->Right));
	while(((*pt)!=NULL) && (checkSNT((*pt)->Data)))
			deleteNode(&(*pt));
	if((*pt)!=NULL)
		deleteSNT(&((*pt)->Left));
}

int main(){
	Tree T;
	makeNullTree(&T);
	int n, x;
	printf("Nhap so Node: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Nhap so node thu %d: ",(i+1));
		scanf("%d",&x);
		insertNode(x, &T);
	}
	
	//RNL(T);
	
	//printf("\n So nut la tren cay la: %d",countLeafNode(T));
	
	deleteSNT(&T);
	
	//printf("\n Cay duyet RNL sau khi xoa Node la SNT: \n");
	printf("\n 	Ket qua xuat ra man hinh la: \n");
	RNL(T);
}
