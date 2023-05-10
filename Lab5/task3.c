#include<stdio.h>
#include<string.h>
char res[100][100];
//here i was created 2 dimentional arry it will store the strings 
int j=0,k=0;
//variable j will count the number of string k will used to put charaters in j location at res array 
void split_String(char s[1000]) //function will accept the string s
{
    
 for(int i=0;i<strlen(s);i++)
 //traversing the string from 0 to length of s 
 {
     if(s[i]!=' ')
     //if s[i] not equal to space then i was storing charater in res at j th location 
     res[j][k++]=s[i];
     else{
         k=0;
         j++;
     }
     // if s[i] is equal to space then i was changing k to 0 and incrementing j by one 
 }
}
int main(){
    char s[1000];
    printf("Enter String Or Phrase: \n",s);
    scanf("%[^\n]s",s);//inputting line 
    split_String(s);//calling function 
  for(int i=0;i<=j;i++){
      printf("'%s'\n",res[i]);//printing the strings
  }
    return 0;
}