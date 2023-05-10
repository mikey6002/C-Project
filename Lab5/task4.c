#include <stdio.h>

void getString(char str[], int length){

   // Getting strings input
      fgets(str, length, stdin);
   
}
   
int main() {
   char str[4][50], temp[50];
   printf("Enter 4 words: ");

   for(int i=0; i<4; i++){
       getString(str[i],sizeof(str[i]));
   }

   // storing strings in the alphabetical order
   for (int i = 0; i < 3; ++i) {
      for (int j = i + 1; j < 4; ++j) {
         // swapping strings if they are not in the alphabetical order
         if (strcmp(str[i], str[j]) > 0) {
            strcpy(temp, str[i]);
            strcpy(str[i], str[j]);
            strcpy(str[j], temp);
         }
      }
   }

   printf("\nIn the alphabetical order: \n");
   for (int i = 0; i < 4; ++i) {
      fputs(str[i], stdout);
   }

return 0;
}