#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>


#define N 5


void matrixMultiplication(int A[][N], int B[][N], int C[][N]) 
{ 
int i, j, k;


for (i = 0; i < N; i++) 
{ 
 for (j = 0; j < N; j++) 
 { 
  C[i][j] = 0;


  for (k = 0; k < N; k++) 
   C[i][j] += A[i][k] * B[k][j]; 
 } 
} 
}


int main() 
{ 
int A[N][N], B[N][N], C[N][N]; 
int i, j;


srand(time(NULL));


for (i = 0; i < N; i++) 
{ 
 for (j = 0; j < N; j++) 
 { 
  A[i][j] = rand() % 10; 
  B[i][j] = rand() % 10; 
 } 
}


matrixMultiplication(A, B, C);


printf("Product of A and B is:\n"); 
for (i = 0; i < N; i++) 
{ 
 for (j = 0; j < N; j++) 
  printf("%d ", C[i][j]);


 printf("\n"); 
}


return 0; 
}