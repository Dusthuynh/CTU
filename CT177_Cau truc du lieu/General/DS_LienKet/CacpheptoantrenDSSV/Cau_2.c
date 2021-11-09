List getList(){
	List L;
	L=(struct Node*)malloc(sizeof(struct Node));
	L->Next=NULL;
	return L;
}
