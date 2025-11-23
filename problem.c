#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define N 100000000
int main()
{
	int *a, *b;
	a = (int*)malloc(sizeof(int) * N);
	b = (int*)malloc(sizeof(int) * N);
	if(!a || !b){
		printf("malloc failed!\n");
		exit(0);
	}
	srand((unsigned int)time(NULL));
	for(int i = 0; i < N; i++) a[i] = b[i] = rand() % N;

	double start1, end1, start2, end2;
	
	start1 = omp_get_wtime();
	for(int i = 0; i < N; i++){
		a[i] = a[a[i]];
	}
	end1 = omp_get_wtime();
	
	start2 = omp_get_wtime();
/******************/
	// write your code here
	for(int i = 0; i < N; i++){
		b[i] = b[b[i]];
	}
/******************/
	end2 = omp_get_wtime();
	
	int flag = 1;
	for(int i = 0; i < N; i++){
		if(a[i] != b[i]) {
			flag = 0;
			printf("Error on index %d, a[%d] = %d b[%d] = %d\n", i, i, a[i], i, b[i]);
			break;
		}
	}
	double t1, t2;
	t1 = end1 - start1;
	t2 = end2 - start2;
	if(flag) printf("The anwser is right!\n t1 = %lf\n t2 = %lf\n speedup = %lf\n", t1, t2, t1 / t2);
	return 0;
}
