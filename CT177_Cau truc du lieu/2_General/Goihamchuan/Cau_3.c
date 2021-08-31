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

void sort(List *L){
    Position p,q;
    ElementType temp;
    for(p=1;p<L->Last;p++)
        for(q=p+1;q<=L->Last;q++)
            if(L->Elements[p-1]>L->Elements[q-1]){
                temp=L->Elements[p-1];
                L->Elements[p-1]=L->Elements[q-1];
                L->Elements[q-1]=temp;
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
    List L;
    readList(&L);
    printList(L);
    sort(&L);
    printList(L);
    return 0;
}
