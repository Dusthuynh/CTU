#include<stdio.h>
#define Maxlength 50
typedef int ElementType;
typedef int Position; 
typedef struct {
	ElementType Elements[Maxlength];
	Position    Last;
} List; 

void makenullList(List *L) {
	L->Last=0;
}

void insertList(ElementType X,Position P, List *L) {
	if (L->Last==Maxlength)
		printf("Danh sach day");	
	else if ((P<1) || (P>L->Last+1))
	    printf("Vi tri khong hop le");
	else {
			Position Q;
			for(Q=(L->Last-1)+1;Q>P-1;Q--)
				L->Elements[Q]=L->Elements[Q-1];
			L->Elements[P-1]=X;
			L->Last++;
		}
} 

Position locate(ElementType X, List L) {
	Position P;
	int Found = 0;
	P = 1;
	while ((P != L.Last+1) && (Found == 0))
		if (L.Elements[P-1] == X) Found = 1;
		else P = P+1;
	return P;
} 

void deleteList(Position P,List *L) { 
	if ((P<1) || (P>L->Last))
		printf("Vi tri khong hop le");
	else if (L->Last==0)
	    printf("Danh sach rong!");
	else {
			Position Q;
			for(Q=P-1;Q<L->Last-1;Q++)
				L->Elements[Q]=L->Elements[Q+1];
			L->Last--;
		}
} 

void erase(ElementType x,List *L) { 
	Position P;
	P=locate(x,*L);
	if (P!=L->Last+1)
	    deleteList(P,L);
} 


void readList(List *L) {	
	int i,N;
	ElementType X;
	makenullList(L);
	scanf("%d",&N);
	for(i=1;i<=N;i++) {
		scanf("%d",&X);
		insertList(X,L->Last+1,L);
	}
}
void printList(List L) {
	Position P;
	P = 1;
	while (P != L.Last+1) {
		printf("%d ",L.Elements[P-1]);
		P = P+1;
	}
	printf("\n");
}
int main(){
    List L;
    ElementType X;
    readList(&L);
    printList(L);
    scanf("%d",&X);
    erase(X,&L);
    printList(L);
    return 0;
}
