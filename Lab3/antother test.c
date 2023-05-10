#include<stdio.h>
int main(){

int base(int x, int y);
    int arr[10], a, b, i, j;
    int ret;
    int z; 
    //Gets user Decimal and stores it to varaible a
    printf("Decimal to Binary conversion\n");
    printf("give me a decimal number for a:  ");
    scanf("%d", &a);

    // Gets user Decimal Number store it to variable b 
    printf("give me a decimal number for b:  ");
    scanf("%d", &b);
    
    // Bitwise OR function
   int orFunction (int a, int b) {
    // array and loop are 32 because inters are 32 bits 
    // if array a has 1 or array b has 1 return a 1 else return a 0
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
   // array and loop are 32 because inters are 32 bits 
   // if array a has 1 and array b has 1 return 1 else return 0 
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
int XOR (int a, int b) {
   int array[32];
   //array and loop are 32 because inters are 32 bits 
   //if array a has 1 and array b has 1 return 0 and if array a has 0 and array b has 0 return 0 if array a has 0 and array b is 1 return 1
   for (int i=0; i < 32; i++) {
     if (a % 2 == 1 && b % 2 == 1 ) {
         array[i] = 0;
      }
     if (a % 2 == 0 && b % 2 == 0 ) {
         array[i] = 0;
     }
     if(a%2==1 && b%2==0){
        array[i]=1;
      }
     if(a%2==0 && b%2==1){
        array[i]=1;
      }
      
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
// print and execute the functions of AND OR and XOR
  printf("The AND of the two numbers is %d \n", AND(a,b));
   printf("The OR  of the two numbers is %d \n", orFunction(a,b));
   printf("The XOR of the two numbers is %d \n", XOR(a,b));

    return 0; 
}

