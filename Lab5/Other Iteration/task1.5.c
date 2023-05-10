#include <stdio.h>
#include <string.h>
#include<stdbool.h>

bool is_substring(char *check, char *string);

int main(void){
    char s1[] = "This is my test string";
    char c1 [] = "test";

    if(is_substring(c1,s1)){
        printf(" '%s' Is a substring of s1 '%s' ", c1,s1);
    }

    else{
        printf(" '%s' is not a substring of '%s' ",c1,s1);
    }
    return 0;
}

bool is_substring(char *check, char *string){
    int slen = strlen(string);
    int clen = strlen(check);

    int end = slen - clen +1;

    for(int i=0; i<end; i++){
        bool check_found = true;

        for(int j=0; j<clen; j++){
            if(check[j] !=string[i+j]){
                check_found = false;
                break;
            }
        }
    if(check_found) return true;
    } 
    return false;
}