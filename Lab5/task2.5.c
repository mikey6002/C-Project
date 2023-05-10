#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
//defining constant SIZE
#define SIZE 256
//defining function sameCount() which accepts two character array
bool sameCount(char* str1, char* str2){
//defining array 'cnt1' 
    int cnt1[SIZE] = { 0 };
    //defining array 'cnt2'
    int cnt2[SIZE] = { 0 };
    //declare variable i as integer
    int i;
    //using for loop, count the frequency of characters in the array
for (i = 0; str1[i] && str2[i]; i++) {
    //converting characters to lowercase using tolower()
    str1[i] = tolower(str1[i]);
    str2[i] = tolower(str2[i]);
    //increment the count of particular element in the array cnt1 and cnt2
    cnt1[str1[i]]++;
    cnt2[str2[i]]++;
}
if (str1[i] || str2[i])
    return false;
    for (i = 0; i < SIZE; i++)
        //checking cnt1[i] not equal to cnt2[i]
        if (cnt1[i] != cnt2[i])
            //if yes, return false
        return false;
            //if not, return true
        return true;
}
int main()
{
//declare character array str1
char str1[SIZE];
//declare character array str2
char str2[SIZE];
printf("Enter the first string: \n");
//getting string from the user
fgets(str1,SIZE,stdin);
printf("Enter the second string: \n");
//getting string from the user
fgets(str2,SIZE,stdin);
//invoking a function sameCount() by passing two strings within if statement
if (sameCount(str1, str2)==true)
    //both strings are having equal length, return 1
    printf("1");
    else
        //if not, return 0
        printf("0");
    return 0;
}