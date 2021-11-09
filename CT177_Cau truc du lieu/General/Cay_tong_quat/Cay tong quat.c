#define maxlength 100
#define nil -1
#include <stdio.h>
typedef char datatype;
typedef int Node;
typedef struct
{
    datatype data[maxlength];
    Node parent[maxlength];
    int maxnode;
} Tree;
//Tree T;
void makenull_tree(Tree *T)
{
    (*T).maxnode=0;
}

Node emptytree(Tree T)
{
    return (T.maxnode==0);
}

Node chacuanut(Node n, Tree T)
{
    if(emptytree(T) || (n>T.maxnode-1))
    {
        return nil;
    }
    else
    {
        return T.parent[n];
    }
}
void ReadTree(Tree *T){
	int i;
	makenull_tree(&T);

	do{
   	printf("Cay co bao nhieu nut?:");
   	scanf("%d",&(*T).maxnode);
	} while (((*T).maxnode<1) || ((*T).maxnode>maxlength));

    fflush(stdin);
	printf("Nhap nhan cua nut goc ");
	scanf("%s",&(*T).data[0]);
	(*T).parent[0]=nil;
	for (i=1;i<=(*T).maxnode-1;i++){
   		printf("Nhap cha cua nut %d ",i);
   		scanf("%d",&(*T).parent[i]);
   		fflush(stdin);
   		printf("Nhap nhan cua nut %d ",i);
   		scanf("%s",&(*T).data[i]);
	}

}
Node Root(Tree T)
{
    if(!emptytree(T))
        return 0;
    else    return nil;
}

Node LeftMostChild(Node n,Tree T)
{
    Node i=n+1;
    int found=0;;
    if(n<0) return nil;
    while(i<T.maxnode && !found)
    {
        if(T.parent[i]==n)
            found=1;
        else
            i++;
    }
    if(found)
        return i;
    else
        return nil;
}
Node RightSibling(Node n,Tree T)
{
    Node cha,i;
    if(n<0) return nil;
    cha = T.parent[n];
    i=n+1;
    int found=0;
    while(i<T.maxnode && !found)
    {
        if(T.parent[i]==cha)
            found=1;
        else
            i++;
    }
    if(found)
        return i;
    else
        return nil;


}
datatype Label_Node(Node n, Tree T)
{
    if (!emptytree(T) && (n<=T.maxnode-1))
    return T.data[n];
}
void PreOrder(Node n,Tree T)
{
    Node i;
    printf("%c ",Label_Node(n,T));
    i=LeftMostChild(n,T);
    while(i!=nil)
    {
        PreOrder(i,T);
        i=RightSibling(i,T);
    }
}
void InOrder(Node n,Tree T)
{
    Node i;
    i=LeftMostChild(n,T);
    if(i!=nil)
        InOrder(i,T);
    printf("%c ",Label_Node(n,T));
    i=RightSibling(i,T);
    while(i!=nil)
    {
       InOrder(i,T);
        i=RightSibling(i,T);
    }
}
void PostOrder(Node n,Tree T)
{
    Node i;
    i= LeftMostChild(n,T);
    while(i!=nil)
    {
        PostOrder(i,T);
        i=RightSibling(i,T);
    }
    printf("%c ",Label_Node(n,T));

}
Node bacnut(Node n, Tree T)
{
    int kq=0;
    Node i;
    i= LeftMostChild(n,T);
    while(i!=nil)
    {
        kq++;
        i=RightSibling(i,T);
    }
    return kq;
}
int max(int a, int b)
{
    return (a>b)?a:b;
}
Node caocay(Node n,Tree T)
{
    int kq;
    if(LeftMostChild(n,T)==nil)
    {
        return 0;
    }
    else
    {
        kq=0;
        Node i=LeftMostChild(n,T);
         while(i!=nil)
         {
              kq=max(kq,caocay(i,T));
              i=RightSibling(i,T);
         }
    }
    return kq+1;
}
Node dosau(Node n, Tree T)
{
    int kq;
    if(T.parent[n]==nil)
    {
        return 0;
    }
    else
    {
        kq=0;
        Node i=chacuanut(n,T);
         while(i!=0)
         {
              kq++;
              i=chacuanut(i,T);
         }
    }
    return kq+1;
}

int totien(Node a, Node d, Tree T)
{
    int kq=0;
    Node i=T.parent[a];
    while(i!=nil)
    {
        if(i==d)
        {
            kq=1;
            return kq;
        }
        else
        {
            i=T.parent[i];
        }
    }
    return kq;
}
Node totienchung(Node p, Node q, Tree T)
{
    if( p==0||q==0)
      return 0;
   else
   {
      while(T.parent[p]!=nil)
      {
         p = T.parent[p];
         Node k = q;
         while(T.parent[k]!=nil)
         {
            k = T.parent[k];
            if( p == k)
               return k;
         }
      }
      return nil;
   }
}

main(){
	Tree T;
	Node i;
	int bac;
	printf("Nhap du lieu cho cay tong quat\n");
	ReadTree(&T);
	/*T.maxnode=10;
	T.parent[0]=-1; T.data[0]='A';
	T.parent[1]=0; T.data[1]='B';
	T.parent[2]=0; T.data[2]='C';
	T.parent[3]=1; T.data[3]='D';
	T.parent[4]=1; T.data[4]='E';
	T.parent[5]=4; T.data[5]='F';
	T.parent[6]=4; T.data[6]='G';
	T.parent[7]=4; T.data[7]='H';
	T.parent[8]=2; T.data[8]='I';
	T.parent[9]=2; T.data[9]='J';*/
	printf("Danh sach duyet tien tu cua cay vua nhap la\n");
	PreOrder(Root(T),T);
	printf("\nDanh sach duyet trung tu cua cay vua nhap la\n");
	InOrder(Root(T),T);
	printf("\nDanh sach duyet hau tu cua cay vua nhap la\n");
	PostOrder(Root(T),T);
	/*bac=bacnut(Root(T),T);
	for(i=1;i<T.maxnode;i++)
	{
	    if(bac<bacnut(i,T))
            bac=bacnut(i,T);
	}
	printf("\nBac cua cay la: %d",bac);
	printf("\nChieu cao cua cay la: %d",caocay(8,T));
    printf("\nDo sau cua mot nut la %d",dosau(3,T));
    printf("\nTo tien cua nut la: %d",totien(5,3,T));
    printf("\nTo tien chung cua nut la: %d",totienchung(3,5,T));*/
}

