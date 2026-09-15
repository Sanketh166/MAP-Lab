#include<stdio.h>
#include<omp.h>

#define SIZE 10

int main(){
	int arr[SIZE] = {12, 45, 7, 89, 23, 99, 56, 34, 67, 10};
	int global_max = arr[0];

	int mid = SIZE/2;
#pragma omp parallel
	{
#pragma omp sections
		{
#pragma omp section
			{
				int local_max = arr[0];
				for(int i=0;i<mid; i++){
					if(arr[i] > local_max){
						local_max = arr[i];
					}
				}
#pragma omp critical
				{
					if(local_max > global_max){
						global_max = local_max;
					}
				}
			}
#pragma omp section
			{
				int local_max = arr[mid];
				for(int i = mid;i<SIZE;i++){
					if(arr[i] > local_max){
						local_max = arr[i];
					}
				}
#pragma omp critical
				{
					if(local_max > global_max){
                                                global_max = local_max;
                                        }       
                                }       
                        }
		}
	}
		 printf("The largest element in the array is: %d\n", global_max);
return 0;}		
