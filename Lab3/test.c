#include<stdio.h>
int main(){

int base(int x, int y);
    int arr[10], a, b, i, j;
    int ret;
    int z; 
    //Gets user Decimal and stores it to varaible a
    printf("Decimal to Binary conversion\n");
    printf("Please give me a decimal number for a:  ");
    scanf("%d", &a);

    // Gets user Decimal Number store it to variable b 
    printf("Please give me a decimal number for b:  ");
    scanf("%d", &b);

    // coverting decimal to binary of a 
    printf("Binary Number of %d is =  ",a);
    for(i = 0; a > 0; i++)
    {
        arr[i] = a % 2;
        a = a / 2;
    }
    for(j = i - 1; j >= 0; j--)  {
        printf(" %d ", arr[j]);
    }
    printf("\n");


    //converting decimal to binary of b
     printf("Binary Number of %d is =  ",b);
    for(i = 0; b > 0; i++){
        arr[i] = b % 2;
        b = b / 2;
    }
    for(j = i - 1; j >= 0; j--)  {
        printf(" %d ", arr[j]);
    }
    printf("\n");
    
    // Bitwise OR function
   int orFunction (int a, int b) {
   int array[32];
   for (int i=0; i < 32; i++) {
      if (a % 2 == 1 || b % 2 == 1) {
         array[i] = 1;
      }
      else array[i] = 0;
      a = a/2;
      b = b/2;
   }

   int answer = 0;
   int multiplier = 1;
   for (int i=31; i >=0; i--) {
      answer = 2 * answer + array[i];
   }
  
   return answer;
}
//Bitwise AND function 
int AND (int a, int b) {
   int array[32];
   for (int i=0; i < 32; i++) {
      if (a % 2 == 1 && b % 2 == 1) {
         array[i] = 1;
      }
      else array[i] = 0;
      a = a/2;
      b = b/2;
   }
   int answer = 0;
   int multiplier = 1;
   for (int i=31; i >=0; i--) {
      answer = 2 * answer + array[i];
   }
  
   return answer;
}
//Bitwise XOR function
int XOR (int a, int b) {
   int array[32];
   for (int i=0; i < 32; i++) {
      if (a % 2 == 1 && b % 2 == 1) {
         array[i] = 0;
      }
      else array[i] = 1;
      a = a/2;
      b = b/2;
   }
   int answer = 0;
   int multiplier = 1;
   for (int i=31; i >=0; i--) {
      answer = 2 * answer + array[i];
   }
  
   return answer;
}
  printf("The AND of the two numbers is %d \n", AND(a,b));
   printf("The OR  of the two numbers is %d \n", orFunction(a,b));
   printf("The XOR of the two numbers is %d \n", XOR(a,b));

    return 0; 
}

