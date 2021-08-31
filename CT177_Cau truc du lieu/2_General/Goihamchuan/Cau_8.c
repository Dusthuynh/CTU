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
int member(ElementType X, List L){
    Position P=1;
    int Found=0;
    while (P!=L.Last+1 && !Found)
        if(L.Elements[P-1]==X)
            Found=1;
        else P=P+1;   
    return Found;
}
void insertSet(ElementType X, List *L) {
     if (L->Last==Maxlength)
 		printf("Danh sach day\n");
 	else {
	    L->Elements[L->Last]=X;
	    L->Last=L->Last+1;
 	}
} 
void readSet(List *L) {	
	int i,N;
	ElementType X;
	makenullList(L);
	scanf("%d",&N);
	for(i=1;i<=N;i++) { 
		scanf("%d",&X);
		if (!member(X,*L))
		    insertSet(X,L);
	}
}

void intersection(List L1, List L2, List *pL){
    makenullList(pL);
    Position p=1;
    while (p!=L1.Last+1){
        if (member(L1.Elements[p-1],L2)){
            insertSet(L1.Elements[p-1],pL);
        }
        p++;
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
    List L1, L2, L3;    
    readSet(&L1);
    readSet(&L2);
    printList(L1);
    printList(L2);
    intersection(L1,L2,&L3);
    printList(L3);
    return 0;
}
