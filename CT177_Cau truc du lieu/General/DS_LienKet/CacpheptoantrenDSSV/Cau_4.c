int append(Student s, List *pL){
	struct Node *P, *temp;
	P=locate(s.ID,(*pL));
	if (P->Next!=NULL){
		return 0;
	}
	else{
		temp=(struct Node*)malloc(sizeof(struct Node));
		temp->Element=s;
		temp->Next=NULL;
		P->Next=temp;
		return 1;
	}	
}
