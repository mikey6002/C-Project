#include <stdio.h>

int main()
{
  //Prints value of sc SC 
//data value dont change because asking for the original signed char which is -7 
    signed char sc = -7;
    printf("For signed char \n");
    printf("Dec : %d \n", sc);
    printf("Hex : %X \n\n", sc);
    
    //prints value of usc
  //data value changed turning signed char into unsigned char which gives new value  
    printf("For signed char \n");
    unsigned char usc = sc;
    printf("For signed char \n");
    printf("Dec : %d \n", usc);
    printf("Hex : %X \n\n", usc);
    
    //prints value of sx
    //Data is refering to signed char  
    short sx = sc;
    printf("For signed char \n");
    printf("Dec : %d \n", sx);
    printf("Hex : %X \n\n", sx);

    //prints valye of usx
    //Data value is changed since converting signed to unsigned short that has range of 0,65,535 and subtract 7 to the possibilites 
    unsigned short usx = sc;
    printf("For signed char :\n");
    printf("Dec : %d \n", usx);
    printf("Hex : %X \n\n", usx);
    
   

   //print value of usy
    //Data value is changed since converting signed to unsigned short that has range of 0,65,535 and subtract 7 to the possibilites 
    unsigned short usy = sx;
    printf("For signed char :\n");
    printf("Dec : %d \n", usy);
    printf("Hex : %X \n\n", usy);
    
    //Print values of TY
    //Data type don't change, it is referring back to the -7  
    int ty = sc;
    printf("For signed char\n");
    printf("Dec : %d \n", ty);
    printf("Hex : %X \n\n", ty);
    
    
    
    //Print programs to display the values of the variable TY
    //Data type don't change, it is referring back to the -7 int 
    unsigned int uty = ty;
    printf("For signed char \n");
    printf("Dec : %d \n", uty);
    printf("Hex : %X \n\n", uty);
    
    return 0;
}