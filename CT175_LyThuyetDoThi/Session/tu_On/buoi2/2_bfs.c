#include <stdio.h>
#define Max_Vertices 100
int mark[Max_Vertices];
int parent[Max_Vertices];
typedef struct{
	int A[Max_Vertices][Max_Vertices];
	int n;
}Graph;

typedef struct{
	int data[Max_Vertices];
	int front, rear;
}Queue;

typedef struct{
	int A[Max_Vertices];
	int size;
}List;

void make_null_queue(Queue *Q){
	Q->front=0;
	Q->rear=-1;
}

void push(Queue *Q, int x){
	Q->rear++;
	Q->data[Q->rear] = x;
}

int top(Queue *Q){
	return Q->data[Q->front];
}

void pop(Queue *Q){
	Q->front++;
}

int empty(Queue *Q){
	return Q->front > Q->rear;
}

void make_null_list(List *L){
	L->size=0;
}
void push_list(List *L, int x){
	L->A[L->size]=x;
	L->size++;
}
List neighbors(Graph *G, int x){
	List L;
	make_null_list(&L);
	int i;
	for(i=1;i<=G->n;i++){
		if((G->A[x][i]!=0 || G->A[i][x]!=0) && x!=i)
			push_list(&L,i);
	}
	return L;
}
void init_graph(Graph *G, int n){
	G->n = n;
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			G->A[i][j]=0;
}
void add_edge(Graph *G,int x, int y){
	G->A[x][y]++;
	G->A[y][x]++;
}

void breath_first_search(Graph *G, int start){
	int i;
	Queue Q;
	make_null_queue(&Q);
	push(&Q, start);
	
	while(!empty(&Q)){
		int x = top(&Q);
		pop(&Q);
		if(mark[x]==0){
			mark[x]=1;
			
			List L = neighbors(G,x);
			for(i=0;i<L.size;i++){
				if(parent[L.A[i]]==-1) parent[L.A[i]] = x;
				push(&Q, L.A[i]);
			}
		}
	}
	for(i=1;i<=G->n;i++){
		if(mark[i]==0){
			parent[i]=0;
			breath_first_search(G,i);
		}
	}
	
}

int main(){
	freopen("dothi.txt","r",stdin);
	int i, u,v, m,n;
	Graph G;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=0;i<m;i++){
		scanf("%d%d",&v,&u);
		add_edge(&G, u, v);
	}
	
	for(i=1;i<=G.n;i++){
		mark[i]=0;
		parent[i]=-1;
	}
	parent[1]=0;
	breath_first_search(&G, 1);
	for(i=1;i<=G.n;i++)
		printf("%d %d\n",i,parent[i]);
}
