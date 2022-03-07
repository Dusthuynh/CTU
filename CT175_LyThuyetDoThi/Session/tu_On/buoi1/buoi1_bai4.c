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
	G->A[x][y] = 1;
	G->A[y][x] = 1;
}

int degree(Graph *G, int x){
	int y, deg = 0;
	for(y=1;y<=G->n;y++)
		if(G->A[x][y] > 0)
			deg++;
	return deg;
}
int main(){
	Graph G;
	init_graph(&G,4);
	add_edge(&G,1,3);
	add_edge(&G,2,4);
	add_edge(&G,1,2);
	add_edge(&G,2,3);
	add_edge(&G,4,3);
	int v;
	for(v=1;v<=G.n;v++)
		printf("degree(%d) = %d\n",v,degree(&G,v));		
}
