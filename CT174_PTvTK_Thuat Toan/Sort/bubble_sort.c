#include <stdio.h>

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(int arr[], int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
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

    bubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}
