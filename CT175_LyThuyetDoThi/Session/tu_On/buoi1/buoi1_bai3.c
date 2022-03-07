#include <stdio.h>
#define MAX_VERTICES 100
#define MAX_EDGE 100

typedef struct{
	int A[MAX_VERTICES][MAX_EDGE];
	int m, n;
}Graph;

void init_graph(Graph *G, int n, int m){
	int i,j;
	G->m=m;
	G->n=n;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			G->A[i][j] = 0;
}

void add_edge(Graph *G, int e, int x, int y){
	G->A[x][e] = 1;
	G->A[y][e] = 1;
}

int adjacent(Graph *G, int x, int y){
	int e;
	for(e=1;e<=G->m;e++)
		if(G->A[x][e] == 1 && G->A[y][e] == 1)
			return 1;
	return 0;
}

int degree(Graph *G, int x){
	int e,deg=0;
	for(e=1;e<=G->m;e++){
		if(G->A[x][e] == 1)
			deg++;
	}
	return deg;
}

int main(){
	Graph G;
	freopen("dothi.txt","r",stdin);
	int i,n,m,u,v,k;
	scanf("%d%d",&n,&m);
	init_graph(&G,n,m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,i,u,v);
	}
	for(k=1;k<=n;k++)
		printf("deg(%d) = %d\n",k,degree(&G,k));
	return 0;
}
