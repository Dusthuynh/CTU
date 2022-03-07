#include <stdio.h>
#define Max_V 100
#define Max_E 500

typedef struct{
	int n,m;
	int A[Max_V][Max_E];
}Graph;

void init(Graph *G, int n, int m){
	int i,j;
	G->m = m;
	G->n = n;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			G->A[i][j]=0;
}

void add_edge(Graph *G, int e, int x, int y){
	G->A[x][e]=1;
	G->A[y][e]=1;
}

int adjacent(Graph* G, int x, int y){
	int i;
	for(i=1;i<G->m;i++){
		if(G->A[x][i]==1 && G->A[y][i]==1)
			return 1;
	}
	return 0;
}

int degree(Graph* G, int x){
	int res=0, i;
	for(i=1; i<=G->m; i++)
		if(G->A[x][i]==1)
			res++;
	return res;
}
int main() {
	Graph G;
	int n = 4, m = 5, v;
	init(&G, n, m);
	add_edge(&G, 1, 1, 2);
	add_edge(&G, 2, 1, 3);
	add_edge(&G, 3, 1, 3);
	add_edge(&G, 4, 3, 4);
	add_edge(&G, 5, 1, 4);
	for (v = 1; v <= n; v++)
	printf("deg(%d) = %d\n", v, degree(&G, v));
	return 0;
}
