#include <stdio.h>

int main(){
	int i=0, x, y, nguyen[100], thuc[100];
	freopen("data.txt","r",stdin);
	while(scanf("%d%f",&x,&y) != EOF){
		scanf("%d%f",&nguyen[i],&thuc[i]);
		i++;
	}
	int n = i+1;
	printf("nguyen:\n");
	for(i=0;i<n;i++){
		printf("%d ",nguyen[i]);
	}
	printf("\n thuc:\n");
		for(i=0;i<n;i++){
		printf("%f ",thuc[i]);
	}
}
