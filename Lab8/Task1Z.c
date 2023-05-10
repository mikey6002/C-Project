#include<stdio.h>
#include<stdlib.h>
#include <time.h> 
#include <math.h>

// function to multiply two 5x5 matrix using the 6 different "IJK" orders
void IJK(int m[5][5], int n[5][5], int result[5][5]){
  for(int i=0; i < 5; i++){
    for(int j=0; j < 5; j++){
      result[i][j] = 0; // assign 0
      // find product
      for (int k = 0; k < 2; k++)
      result[i][j] += m[i][k] * n[k][j];
    }
  }
}
void JKI(int m[5][5], int n[5][5], int result[5][5]){
  for(int j=0; j < 5; j++){
    for(int k=0; k < 5; k++){
      result[j][k] = 0; // assign 0
      // find product
      for (int i = 0; i < 5; i++)
      //first second, first last, last second 
      result[j][k] += m[j][i] * n[i][k];
    }
  }
}
void KIJ(int m[5][5], int n[5][5], int result[5][5]){
  for(int k=0; k < 5; k++){
    for(int i=0; i < 5; i++){
      result[k][i] = 0; // assign 0
      // find product
      for (int j = 0; j < 5; j++)
      result[k][i] += m[k][j] * n[j][i];
    }
  }
}
void JIK(int m[5][5], int n[5][5], int result[5][5]){
  for(int j=0; j < 2; j++){
    for(int i=0; i < 5; i++){
      result[j][i] = 0; // assign 0
      // find product
      for (int k = 0; k < 2; k++)
      result[j][i] += m[j][k] * n[k][i];
    }
  }
}
void KJI(int m[5][5], int n[5][5], int result[5][5]){
  for(int k=0; k < 2; k++){
    for(int j=0; j < 2; j++){
      result[k][j] = 0; // assign 0
      // find product
      for (int i = 0; i < 2; i++)
      result[k][j] += m[k][i] * n[i][j];
    }
  }
}
void IKJ(int m[5][5], int n[5][5], int result[5][5]){
  for(int i=0; i < 2; i++){
    for(int k=0; k < 5; k++){
      result[i][k] = 0; // assign 0
      // find product
      for (int j = 0; j < 2; j++)
      result[i][k] += m[i][j] * n[j][k];
    }
  }
}

// function to display 3x3 matrix
void display(int matrix[5][5])
{
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++)
      printf("%d\t",matrix[i][j]);

    printf("\n"); // new line
  }
}

// main function --- this is where everything just went completely south, I don't know how to fix this 
int main()
srand(time(NULL));

  m[i][j] = rand() % 10; 
  n[i][j] = rand() % 10; 
 
  
  printf("First Matrix:\n");
  display(m);
  printf("Second Matrix:\n");
  display(n);


//now trying to multipy these two random number generated matrices 
printf("\n");
    IJK(m, n, result);
        printf("Multiplication of matrix IJK: \n");
        display(result);
        //break;
    JKI(m, n, result);
        printf("Multiplication of matrix JKI: \n");
        display(result);
        //break;
    KIJ(m, n, result);
        printf("Multiplication of matrix KIJ: \n");
        display(result);
        //break;
    IKJ(m, n, result);
        printf("Multiplication of matrix IKJ: \n");
        display(result);
        //break;
    JIK(m, n, result);
        printf("Multiplication of matrix JIK: \n");
        display(result);
        //break;
    KJI(m, n, result);
        printf("Multiplication of matrix KJI: \n");
        display(result);

  return 0;
}