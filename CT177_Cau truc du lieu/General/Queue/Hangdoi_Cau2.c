#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElementType;
struct Node {
	ElementType Element;
	struct Node	*Next;
};
typedef struct Node* Position;
typedef struct {
	Position Front, Rear;
} Queue; 

void makenullQueue(Queue *pQ) {
	Position Header;
	Header=(struct Node*)malloc(sizeof(struct Node)); 
	Header->Next=NULL;
	pQ->Front=Header;
	pQ->Rear=Header;
}

int emptyQueue(Queue Q) {
	return (Q.Front==Q.Rear);
} 

void enQueue(ElementType X, Queue *pQ) { 
	pQ->Rear->Next=(struct Node*)malloc(sizeof(struct Node));
	pQ->Rear=pQ->Rear->Next;
	pQ->Rear->Element=X;
	pQ->Rear->Next=NULL;
} 

void deQueue(Queue *pQ) {
	if (!emptyQueue(*pQ)){
		Position Tempt;
		Tempt=pQ->Front;
		pQ->Front=pQ->Front->Next;
		free(Tempt);
	}
	else 
		printf("Loi: Hang rong");
 } 

ElementType front(Queue Q) {
	if (!emptyQueue(Q))
		return Q.Front->Next->Element;
	else {
	    printf("Loi, hang rong");
	    return -1;
	}	
} 

int countElements(Queue Q){
    Position P=Q.Front;
    int count=0;
    while(P!=Q.Rear){
        count++;
        P=P->Next;
    }
    return count;
}

int main() {
	Queue Q;
	int x,i,N,temp;
	char kt;
	scanf("%d",&N);
	scanf(" ");
	makenullQueue(&Q);
	for(i=1;i<=N;i++){
	   scanf("%c",&kt); 
	   if(kt=='E'){
	       scanf("%d",&x);
	       scanf(" ");
	       enQueue(x,&Q);
	       printf("%d\n",countElements(Q));
	   }
	   else if (kt=='D'){
	       scanf(" ");
	       if(!emptyQueue(Q)){
	            temp=front(Q);
	            deQueue(&Q);
	            printf("%d %d\n",temp,countElements(Q));
	            
	       }
	       else 
	            printf("-1 0\n");
	   }
	}
	return 0;
} 

 

  
