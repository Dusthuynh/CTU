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

void printOddNumbers(List L){
    Position p=1;
    while (p!=L.Last+1){
        if (L.Elements[p-1]%2!=0)
            printf("%d ",L.Elements[p-1]);
        p++;    
    }
}

void copyEvenNumbers(List L1, List *L2){
    makenullList(L2);
    ElementType X;
    Position p=1;
    while (p!=L1.Last+1){
        X=L1.Elements[p-1];
        if (X%2==0)
            insertList(X,L2->Last+1,L2);
        p++;    
    }
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
    List L, L2;
    readList(&L);
    printList(L);
    printOddNumbers(L);
    printf("\n");
    copyEvenNumbers(L,&L2);
    printList(L2);
    return 0;
}
