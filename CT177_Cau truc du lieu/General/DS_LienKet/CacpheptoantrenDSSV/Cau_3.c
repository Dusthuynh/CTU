struct Node *locate(char[] x, List L){
	struct Node *P=L;
	int Found=0;
	while (P->Next!=NULL && !Found){
		if (strcmp(P->Next->Element.ID,x)==0)
			Found=1;
		else
			P=P->Next;
	}
	return P;	
}
