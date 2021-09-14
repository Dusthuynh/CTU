struct Node *p=L;
int count=1;
float avg;
while(p->Next!=NULL){
	avg=(p->Next->Element.R1+p->Next->Element.R2+p->Next->Element.R3)/3;
	printf(" %d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n",count,p->Next->Element.ID, 
      p->Next->Element.Name, p->Next->Element.R1, p->Next->Element.R2,
      p->Next->Element.R3, avg);			
    count++;  
	p=p->Next;
}
//-END-SECTION-
List L;
L=readList();
printList(L);
