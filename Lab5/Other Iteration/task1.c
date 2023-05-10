#include<stdio.h>
#include<string.h>
int check_Sub_String(int *s[1000],int *s1[1000]){
    
    //check_Sub_string is the function will accept two string s and s1;
    for(int i=0;i<strlen(s)-strlen(s1);i++)
    {
        //in first loop we are traversing from 0 to length of firststring -second string 
        int c=0;
        // we assing zero to variable c is used to find the count of matched characters 
        for(int j=i;j<strlen(s1)+i;j++) 
        {
            // here we are traversing from i to length of string s1+i in s
            if(s[i]==s1[i])//if s[i]==s1[i] then we are incrementing count by one
            c++;
        }
        if(c==strlen(s1))//if the c==lenght of s1 then we are returing one 
        return 1;
    }
    return 0;
    //if it not found any matched string it will return 0
}
int main()
{
    int s[1000],s1[1000];
    printf("Enter in a string :",s);
    scanf("%[^\n]s",s);
    //accepting line input 
    printf("Enter second string :",s1);
    scanf("%s",s1);
    
    //in the program we it was mention that it was case sensitive so i was converting the characters 
    //if the charater is in upper case i was converting it into lower case 
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='A' && s[i]<='Z')
        s[i]+=32;
    }
    for(int i=0;i<strlen(s1);i++)
    {
       if(s1[i]>='A' && s1[i]<='Z')
       s1[i]+=32;
    }
  printf("%d",check_Sub_String(s,s1));
  //method calling 
    
}