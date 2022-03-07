#include <stdio.h>

void swap(int *x, int *y){
	int temp = *x;
		*x	 = *y;
		*y	 = temp;
}

void selectionSort(int arr[], int n){
	int i,j,idx_min;
	for(i=0;i<n;i++){
		idx_min=i;
		for(j=i+1;j<n;j++){
			if(arr[j] < arr[idx_min])
				idx_min = j;
		}
		swap(&arr[i],&arr[idx_min]);
	}
}

void printArray(int arr[], int size){
	int i;
	printf("Array after:\n");
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
}

int main(){
	int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    selectionSort(arr, n);
    printArray(arr, n);
 
    return 0;
}
