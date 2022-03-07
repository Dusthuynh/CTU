#include <stdio.h>

void quickSort(int arr[],int n, int m){
	int l = n, r = m, c=1;
	if(n<m){
		int pivot = arr[n];
		while(r!=l){
			if(c==1){
				if(arr[r] >= pivot)
					r--;
				else{
					arr[l] = arr[r];
					l++;
					c=0;
				}	
			}else{
				if(arr[l] <= pivot)
					l++;
				else{
					arr[r] = arr[l];
					r--;
					c=1;
				}
			}
		}
		arr[r] = pivot;
		quickSort(arr, n, l-1);
		quickSort(arr, l+1, m); 	
	}
}

void printArray(int arr[], int size){
	int i;
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
}

int main(){
	int arr[] = { 5, 6, 2 , 10, 4, 7, 3, 15, 1, 26, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}
