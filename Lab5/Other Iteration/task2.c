#include <stdio.h>
#include <string.h>

void printFrequency(int freq1[], int freq2[]) {  // Called function receive two strings
  printf("Frequency of the first string:\n");
  for (int i = 0; i < 26; i++) { // Loop runs for all the characters         

    if (freq1[i] != 0) {        // if the frequency is not 1

      printf("%c - %d\n",

             i + 'a', freq1[i]); // print the frequency of characters
    }
  }

  printf("\nFrequency of the second string:\n");
  for (int i = 0; i < 26; i++) { // Loop runs for all the characters 

    if (freq2[i] != 0) {        // if the frequency is not 1

      printf("%c - %d\n",

             i + 'a', freq2[i]); // print the frequency of characters
    }
  }
}

void findFrequncy(char S1[], char S2[])  // Called function receive two strings

{
  int i = 0;   // variable declaration 
  int j = 0;   // variable declaration 

  int freq1[26] = {0};   // Assign frequency of all characters of string 1 to 0
  int freq2[26] = {0};   // Assign frequency of all characters of string 2 to 0

  while (S1[i] != '\0') { // Loop  runs for all the characters of s1
    if (S1[i] >= 'a' && S1[i] <= 'z') {  // Check the charater is in lower case    
      freq1[S1[i] - 'a']++;              // Increment the character count by 1
      i++;                               // Increment the index value by 1
    }

    if (S1[i] >= 'A' && S1[i] <= 'Z') {  // Check the charater is in upper case  
      freq1[S1[i] - 'A']++;              // Increment the character count by 1
      i++;                               // Increment the index value by 1
    }
  }
  
  while (S2[j] != '\0') { // Loop  runs for all the characters of s2

    if (S2[j] >= 'a' && S2[j] <= 'z') {  // Check the charater is in lower case 
      freq2[S2[j] - 'a']++;              // Increment the character count by 1
      j++;                               // Increment the index value by 1
    }

    if (S2[j] >= 'A' && S2[j] <= 'Z') {  // Check the charater is in upper case 
      freq2[S2[j] - 'A']++;              // Increment the character count by 1
      j++;                               // Increment the index value by 1
    }
  }

  printFrequency(freq1, freq2);      // calling function pass freq1 and freq2
}

int main()
{
  char S1[100] = "Pizza";       // variable declaration
  char S2[100] = "Burger";      // variable declaration

  findFrequncy(S1, S2);         // Calling function pass s1 and s2
}