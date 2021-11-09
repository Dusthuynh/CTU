#include <stdio.h>
#include <malloc.h>

	struct Node{
		int Key;
		struct Node *Left,*Right;
	};
	typedef struct Node* Tree;
	
	void makenullTree(Tree *pT){
		(*pT)=NULL;
	}
	
	void insertNode(int x, Tree *pT){
		if((*pT)==NULL){
			(*pT)=(struct Node*)malloc(sizeof(struct Node));
			(*pT)->Key=x;
			(*pT)->Left=NULL;
			(*pT)->Right=NULL;
		}else
			if(x > (*pT)->Key)	insertNode(x,&(*pT)->Right);
		else
			if(x < (*pT)->Key) insertNode(x,&(*pT)->Left);
	}
	
	void LNR(Tree T){
		if(T!=NULL){
			LNR(T->Left);
			printf("%d ",T->Key);
			LNR(T->Right);
		}
	}
	
	int sumValueNode(Tree T){
		if(T==NULL)	return 0;
		else return T->Key + sumValueNode(T->Left) + sumValueNode(T->Right);
	}
	
	int main(){
		Tree T;
		makenullTree(&T);
		insertNode(54,&T);
		insertNode(31,&T);
		insertNode(65,&T);
		insertNode(29,&T);
		insertNode(43,&T);
		insertNode(59,&T);
		insertNode(78,&T);
		insertNode(10,&T);
		insertNode(36,&T);
		insertNode(20,&T);
		LNR(T);
		printf("Sum: %d ",sumValueNode(T));
	}

