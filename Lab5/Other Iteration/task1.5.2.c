#include <stdio.h>
#include<stdbool.h>
#include <string.h>

int is_substring(char check, char *string);

int main(void)
{
    //String
    char s1[] = "test searching";
    //substring to be searched
    char c1[] = "test";
    //calling the function
    if (is_substring(c1, s1))
        printf("1\n");
    else
        printf("0\n");
    return 0;

}

//Function to check substring is present or not in string
int is_substring(char check, char *string)
{
    //temporary variable
    bool check_found;
    int slen = strlen(string);
    int clen = strlen(check);
    int end = slen - clen ;
    //Outer loop for iterating through string
    for (int i = 0; i < end; i++)
    {
        //Inner loop
        for (int j = 0; j <i+clen; j++)
        {
            check_found = true;
            //If substring is not found
            if (check[j] != string[i+j])
            {
                check_found = false;
                break;
            }
        }

    if (check_found)
            break;
    }
    //If substring is found
    if (check_found)
    { 
        return true;
    }

    return false;


}