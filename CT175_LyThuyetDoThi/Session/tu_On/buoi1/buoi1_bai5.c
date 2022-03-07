#include <stdio.h>
#define MAX_VERTICES 100
typedef struct{
	int A[MAX_VERTICES][MAX_VERTICES];
	int n;
}Graph;

void init_graph(Graph *G, int n){
	G->n = n;
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<n;j++)
			G->A[i][j] = 0;
}

int adjacent(Graph *G, int x, int y){
	G->A[x][y] != 0;
}

void add_edge(Graph *G, int x, int y){
	G->A[x][y] += 1;
	G->A[y][x] += 1;
}

int degree(Graph *G, int x){
	int y, deg = 0;
	for(y=1;y<=G->n;y++)
		if(G->A[x][y] > 0)
			deg+= G->A[x][y];
	return deg;
}
int main(){
	Graph G;
	int n, m, u, v, i, k;
	freopen("dothi.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	for(k=1;k<=n;k++){
		printf("deg(%d) = %d\n",k,degree(&G,k));
	}
	return 0;	
}
