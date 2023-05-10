#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
    


//Define Function IJK 
void IJK (int A[5][5], int B[5][5], int C[5][5]) { 
  // multiple each row of "i" by each column "j"
  int i, j, k;
  // first loop (i) iterates through the rows
  for (i = 0; i < 5; i++) { 
    //second loop (j) iterates through the columns
    for (j = 0; j < 5; j++) { 
      C[i][j] = 0;
      //(k) iterates through the elements in row i of matrix A and column j of matrix B, multiplying each element and summing the products.
      for (k = 0; k < 5; k++) 
        C[i][j] += A[i][k] * B[k][j]; 
      } 
  } 
}
    
void JKI (int A[5][5], int B[5][5], int C[5][5]) { 
  // multiple each row of "i" by each column "j"
  int i, j, k;
  // first loop (i) iterates through the rows
  for (i = 0; i < 5; i++) {
        //second loop (j) iterates through the column
    for (j = 0; j < 5; j++) { 
      C[i][j] = 0;
            //(k) iterates through the elements in row i of matrix A and column j of matrix B, multiplying each element and summing the products.
      for (k = 0; k < 5; k++) 
        C[i][j] += A[i][k] * B[k][j]; 
      } 
  } 
}
void KJI (int A[5][5], int B[5][5], int C[5][5]) { 
  // multiple each row of "i" by each column "j"
  int i, j, k;
  // first loop (i) iterates through the rows
  for (i = 0; i < 5; i++) { 
        //second loop (j) iterates through the columns
    for (j = 0; j < 5; j++) { 
      C[i][j] = 0;
            //(k) iterates through the elements in row i of matrix A and column j of matrix B, multiplying each element and summing the products.
      for (k = 0; k < 5; k++) 
        C[i][j] += A[i][k] * B[k][j]; 
      } 
  } 
}
    
void JIK (int A[5][5], int B[5][5], int C[5][5]) { 
  // multiple each row of "i" by each column "j"
  int i, j, k;
  // first loop (i) iterates through the rows
  for (i = 0; i < 5; i++) { 
        //second loop (j) iterates through the columns
    for (j = 0; j < 5; j++) { 
      C[i][j] = 0;
            //(k) iterates through the elements in row i of matrix A and column j of matrix B, multiplying each element and summing the products.
      for (k = 0; k < 5; k++) 
        C[i][j] += A[i][k] * B[k][j]; 
      } 
  } 
}


void IKJ (int A[5][5], int B[5][5], int C[5][5]) { 
  // multiple each row of "i" by each column "j"
  int i, j, k;
  // first loop (i) iterates through the rows
  for (i = 0; i < 5; i++) { 
        //second loop (j) iterates through the columns
    for (j = 0; j < 5; j++) { 
      C[i][j] = 0;
            //(k) iterates through the elements in row i of matrix A and column j of matrix B, multiplying each element and summing the products.
      for (k = 0; k < 5; k++) 
        C[i][j] += A[i][k] * B[k][j]; 
      } 
  } 
}
    
void KIJ (int A[5][5], int B[5][5], int C[5][5]) { 
  // multiple each row of "i" by each column "j"
  int i, j, k;
  // first loop (i) iterates through the rows
  for (i = 0; i < 5; i++) {
        //second loop (j) iterates through the columns 
    for (j = 0; j < 5; j++) { 
      C[i][j] = 0;
            //(k) iterates through the elements in row i of matrix A and column j of matrix B, multiplying each element and summing the products.
      for (k = 0; k < 5; k++) 
        C[i][j] += A[i][k] * B[k][j]; 
      } 
  } 
}

void display(int matrix[5][5]){
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++)
      printf("%d\t",matrix[i][j]);

    printf("\n"); // new line
  }
}


int main() { 
    int A[5][5], B[5][5], C[5][5]; 
  int i, j; 
   srand(time(NULL));
for (i = 0; i < 5; i++) 
{ 
 for (j = 0; j < 5; j++) 
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