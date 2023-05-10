#include<stdio.h>
/* Function declaration */
int compareFiles(FILE * fPtr1, FILE * fPtr2 ,int * line, int * col );
     
     
     
     /* File pointer to hold reference of input file */
int main() {
    
    FILE *fPtr1; 
    FILE *fPtr2;

    char path1[40];
    char path2[40];
    int diff;
    int line, col;
    
    /* Input path of files to compare */
    printf("Enter name of first file :");
    gets(path1);
 
    printf("Enter name of second file:");
    gets(path2);
    
    /*  Open all files to compare */
    fPtr1 = fopen(path1, "r");
    fPtr2 = fopen(path2, "r");

    /* fopen() return NULL if unable to open file in given mode. */
    if(fPtr1 ==NULL){
        printf("Cant open %s",fPtr1);
        exit(1);
    }
     /* Unable to open file exit */
    else if(fPtr2==NULL){
        printf("Cant open %s",fPtr2);
        exit(1);
    }
    /* Call function to compare file */
    diff = compareFiles(fPtr1,fPtr2, &line, &col);
        if(diff==0){
            printf("Both Files are  equal");
        }
        else{
            printf("Files are not equal ");
            printf("Line: %d, col: %d\n", line, col);
        }
   
/* close files to release resources */
    fclose(fPtr1);
    fclose(fPtr2);
    
    
    return 0;
}
/**
 * Function to compare two files.
 * Returns 0 if both files are equivalent, otherwise returns
 * -1 and sets line and col where both file differ.
 */
int compareFiles(FILE * fPtr1, FILE * fPtr2,int * line, int * col){
    char ch1, ch2;
    char path1[40], path2[40];
    *line = 1;
    *col  = 0;
// Input character from both files
  do{
    ch1 =fgetc(fPtr1);
    ch2 =fgetc(fPtr2);

    if(ch1== '\n'){
         *line += 1;
        *col = 0;
    }
 // If characters are not same then return -1
    if(ch1 !=ch2){
        return -1;
    *col  += 1;

    }
  }

while(ch1!=EOF && ch2 != EOF);
  
  /* If both files have reached end */
  if (ch1 == EOF && ch2 == EOF)
        return 0;
    else
        return -1;


}