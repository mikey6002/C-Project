
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <math.h>

#define N 80

void IJK (int A[][N], int B[N][5], int C[][N]) { 
  // multiple each row of "i" by each column "j"
  int i, j, k;
  // first loop (i) iterates through the rows
  for (i = 0; i < N; i++) { 
    //second loop (j) iterates through the columns
    for (j = 0; j < N; j++) { 
      C[i][j] = 0;
      //(k) iterates through the elements in row i of matrix A and column j of matrix B, multiplying each element and summing the products.
      for (k = 0; k < N; k++) 
        C[i][j] += A[i][k] * B[k][j]; 
      } 
  } 
  //Count how many ticks to finish this function
long tick1 = clock();
printf("Program took %ld ms : ",tick1);
}

void JKI (int A[][N], int B[N][N], int C[][N]) { 
  // multiple each row of "i" by each column "j"
  int i, j, k;
  // first loop (i) iterates through the rows
  for (i = 0; i < N; i++) { 
    //second loop (j) iterates through the columns
    for (j = 0; j < N; j++) { 
      C[i][j] = 0;
      //(k) iterates through the elements in row i of matrix A and column j of matrix B, multiplying each element and summing the products.
      for (k = 0; k < N; k++) 
        C[i][j] += A[i][k] * B[k][j]; 
      } 
  } 
  //Count how many ticks to finish this function
long tick1 = clock();
printf("Program took %ld ms : ",tick1);
}

void KJI (int A[][N], int B[N][5], int C[][N]) { 
  // multiple each row of "i" by each column "j"
  int i, j, k;
  // first loop (i) iterates through the rows
  for (i = 0; i < N; i++) { 
    //second loop (j) iterates through the columns
    for (j = 0; j < N; j++) { 
      C[i][j] = 0;
      //(k) iterates through the elements in row i of matrix A and column j of matrix B, multiplying each element and summing the products.
      for (k = 0; k < N; k++) 
        C[i][j] += A[i][k] * B[k][j]; 
      } 
  } 
  //Count how many ticks to finish this function
  long tick1 = clock();
  printf("Program took %ld ms: ",tick1);
}

void JIK (int A[][N], int B[N][5], int C[][N]) { 
  // multiple each row of "i" by each column "j"
  int i, j, k;
  // first loop (i) iterates through the rows
  for (i = 0; i < N; i++) { 
    //second loop (j) iterates through the columns
    for (j = 0; j < N; j++) { 
      C[i][j] = 0;
      //(k) iterates through the elements in row i of matrix A and column j of matrix B, multiplying each element and summing the products.
      for (k = 0; k < N; k++) 
        C[i][j] += A[i][k] * B[k][j]; 
      } 
  } 
  //Count how many ticks to finish this function
long tick1 = clock();
printf("Program took %ld ms: ",tick1);
}

void IKJ (int A[][N], int B[N][5], int C[][N]) { 
  // multiple each row of "i" by each column "j"
  int i, j, k;
  // first loop (i) iterates through the rows
  for (i = 0; i < N; i++) { 
    //second loop (j) iterates through the columns
    for (j = 0; j < N; j++) { 
      C[i][j] = 0;
      //(k) iterates through the elements in row i of matrix A and column j of matrix B, multiplying each element and summing the products.
      for (k = 0; k < N; k++) 
        C[i][j] += A[i][k] * B[k][j]; 
      } 
  } 
    //Count how many ticks to finish this function
long tick1 = clock();
printf("Program took %ld ms :",tick1);
}

void KIJ (int A[][N], int B[N][5], int C[][N]) { 
  // multiple each row of "i" by each column "j"
  int i, j, k;
  // first loop (i) iterates through the rows
  for (i = 0; i < N; i++) { 
    //second loop (j) iterates through the columns
    for (j = 0; j < N; j++) { 
      C[i][j] = 0;
      //(k) iterates through the elements in row i of matrix A and column j of matrix B, multiplying each element and summing the products.
      for (k = 0; k < N; k++) 
        C[i][j] += A[i][k] * B[k][j]; 
      } 
  } 
  //Count how many ticks to finish this function
long tick1 = clock();
printf("Program took %ld ms :",tick1);
}


void display(int matrix[N][N]){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++)
      printf("%d\t",matrix[i][j]);

    printf("\n"); // new line
  }
}



int main() { 
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

  printf("First Matrix:\n");
  display(A);
  printf("Second Matrix:\n");
  display(B);
  printf("\n");
  printf("\n");

    printf("________________________________\n");  
    IJK(A, B, C);
        printf("Multiplication of matrix IJK: \n");
        display(C);
        printf("________________________________\n");
    KIJ(A, B, C);
        printf("Multiplication of matrix KIJ: \n");
        display(C);
     
    JKI(A, B, C);
        printf("Multiplication of matrix JKI: \n");
        display(C);
        printf("________________________________\n");
    JIK(A, B, C);
        printf("Multiplication of matrix JIK: \n");
        display(C);
        printf("________________________________\n");
    KJI(A, B, C);
        printf("Multiplication of matrix KJI: \n");
        display(C);
        printf("________________________________\n");
    IKJ(A, B, C);
        printf("Multiplication of matrix IJK: \n");
        display(C);

  return 0; 
}