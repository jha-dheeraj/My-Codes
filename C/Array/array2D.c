#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, j;
	// Creating a 1D array at Heap.
	int *arr = (int *)malloc(5*sizeof(int));
	for(i=0; i<5; i++)
	{
		arr[i] = 1;
	}
	for(j=0; j<5;j++)
		printf("%d ", arr[j]);
	printf("\n\n");

	// 2D array (partial on heap, partial on stack)
	int *arr1[3];
	arr1[0]= (int *)malloc(3*sizeof(int));
	arr1[1]= (int *)malloc(3*sizeof(int));
	arr1[2]= (int *)malloc(3*sizeof(int));

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
				arr1[i][j]=0;
			else
				arr1[i][j]=1;
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}

	free(arr1[0]);
	free(arr1[1]);
	free(arr1[2]);
	arr1[0]=NULL;
	arr1[1]=NULL;
	arr1[2]=NULL;

	printf("\n\n");

	// Fully Heap based 2D Array allocation.
	int **arr2;
	arr2 = (int **)malloc(3*sizeof(int *));
	arr2[0] = (int *)malloc(3*sizeof(int));
	arr2[1] = (int *)malloc(3*sizeof(int));
	arr2[2] = (int *)malloc(3*sizeof(int));

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
				arr2[i][j]=0;
			else
				arr2[i][j]=2;
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}

	free(arr2[0]);
	free(arr2[1]);
	free(arr2[2]);
	free(arr2);

	return 0;
}
