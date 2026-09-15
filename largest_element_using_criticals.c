#include <stdio.h>
#include <omp.h>

#define SIZE 10

int main() {
	int arr[SIZE] = {12,45,7,89,99,56,35,56,87,10};
	int global_max = arr[0];

#pragma omp parallel for
	for(int i=0; i<SIZE; i++){
#pragma omp critical
		if(arr[i] > global_max){
			global_max = arr[i];
		}
	}

printf("The largest element in the array is: %d\n",global_max);
return 0;
}
