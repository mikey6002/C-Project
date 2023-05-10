#include <stdio.h>

int main() 
{

    char names[4] [20]
        ={
            "C programming",
            "Java",
            "CIS_2107",
            "Temple University"
        };

int i;
int j;
char temp[20]; 
printf("\nGiven array is:\n");
for(i=0;i<4;i++)
{
    printf("%s\n", names[i]);
}
//loop for sorting names 
for(i=0;i<50-1;i++)
{
    for(j=i+1;j<50;j++)

        if(strcmp(names[i],names[j])>0)
        {
            strcpy(temp, names[i]);
            strcpy(names[i], names[j]);
            strcpy(names[j], temp);
        }
    }


    printf("\nSorted array is:\n");
    for(i = 0; i < 4; i++)
    {
        printf("\n%s", names[i]); 
    }
    return 0;
}