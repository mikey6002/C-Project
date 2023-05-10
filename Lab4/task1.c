#include <stdio.h>

// function to calculate the length of the string input and return it
int length(char s[]) {
   int i = 0;
   while(s[i] != '\0') {
      i++;
   }
   return i;
}


// function to reverse the string using recurssion
void reverse(char *s, int start, int end) {
   char c;
   
   // base case
   if (start >= end) {
       return;
       } 

   c = *(s+start);
   *(s+start) = *(s+end);
   *(s+end) = c;
   
   // call function again
   reverse(s, ++start, --end);
}


// function called upper to convert all lowercase letters into uppercase
// function returns number of characters updated
int upper(char s[], int n) {
   int c = 0;
   int count = 0;
   
   while (c != n) {
      if (s[c] >= 'a' && s[c] <= 'z') {
         s[c] = s[c] - 32;

       // counting the characters updated
       count++;
      }
      c++;
   }
   return count;
}


// main function
int main() {
   char str[500];

   // reading string input
   printf("Enter a string: ");
   scanf("%[^\n]%*c", str);

   // calling function to calculate length of string
   int len = length(str);

   // call function to reverse the string
   reverse(str, 0, len-1);

   // call function to update the string to uppercase and return the number of updates
   int upper_chars = upper(str, len);

   // display each character one in line
   int i;
   for(i = 0; i < len; i++) {
      printf("\n%c", str[i]);
   }
   printf("\n\nThe string is %d chars and %d chars were capitalized.", len, upper_chars);
}