List L2;
L2=getList();
struct Node *p=L;
float avg;
while(p->Next!=NULL){
	avg=(p->Next->Element.R1+p->Next->Element.R2+p->Next->Element.R3)/3;
	if (avg<4.0){
		append(p->Next->Element, &L2);
	}
	p=p->Next;
}
return L2;
//-END-SECTION-
List L1,L2;
L1=readList();
printList(L1);
L2=getFailedList(L1);
printList(L2);
