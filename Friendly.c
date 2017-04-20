#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define DIM 4000

void main()
{
	int i,j,sum=0;
	int **a = (int **)malloc(DIM * sizeof(int *));
	for(i=0;i<DIM;i++)
		a[i] = (int *)malloc(DIM * sizeof(int));
	int **b = (int **)malloc(DIM * sizeof(int *));
	for(i=0;i<DIM;i++)
		b[i] = (int *)malloc(DIM * sizeof(int));
	int **c = (int **)malloc(DIM * sizeof(int *));
	for(i=0;i<DIM;i++)
		c[i] = (int *)malloc(DIM * sizeof(int));
	
	for(int i=0;i<DIM;i++)	
		for(int j=0;j<DIM;j++)
			a[i][j] = i+j;

	for(int i=0;i<DIM;i++)	
		for(int j=0;j<DIM;j++)			
			b[i][j] = i+j;		
	
	for(int i=0;i<DIM;i++)	
		for(int j=0;j<DIM;j++)		
			c[i][j] = 0;	

	#pragma omp parallel for
	for(int i=0;i<DIM;i++)	
		for(int j=0; j<DIM;j++)		
			for(int k=0; k<DIM ; k++)			
				c[i][j] = c[i][j] + a[j][k] + b[j][k];
			
	printf("c[56][500]=%d\n", c[56][500]);
}
