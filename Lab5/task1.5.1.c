#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// initiate function
int check_Sub_String(char *sub, char *string);

int main(){
    // set char size 
    char StringFromUser[1000];
    char SubStringFromUser [1000];
    // Asks user for string and substring inputs
    printf("Enter in a string :",StringFromUser); 
    //store user input into StringFrom User using regex(regular expression) and read all characters until reach \n and store it into StringFromUser
        scanf("%[^\n]%*c", &StringFromUser);    
    printf("Enter substring :",SubStringFromUser);
    //store user input into SubStringFromUser using regex(regular expression) and read all characters until reach \n and store it into SubStringFromUser
        scanf("%[^\n]%*c", &SubStringFromUser);
    
    // prints if there is a substring in string
    if(check_Sub_String(SubStringFromUser,StringFromUser)){
        printf(" '%s' Is a substring of '%s' ", SubStringFromUser,StringFromUser);
    }

    else{ 
        // prints if there isn't a substring in string
        printf(" '%s' is not a substring of '%s' ",SubStringFromUser,StringFromUser);
    }

    return 0;
}


//check sub string function 
int check_Sub_String(char *sub, char *string){
    int checklength = strlen(sub);
    int stringlength = strlen(string);

    //check the length of the string but also account the length of substring
    int ending = stringlength - checklength +1;

    for(int i=0; i<ending; i++){
        // checker will be kept at true if there are matches to string
        bool checker = true;
        // increment from 0 to the checklength
        for(int j=0; j<checklength; j++){
            // character doesn't match the characters in the index i +j  we set chceck_found to false since check is not at position in string 
            if(sub[j] !=string[i+j]){
                checker = 0;
                break;
            }
        }
    if(checker) return 1;
    } 
    return 0;

    
}