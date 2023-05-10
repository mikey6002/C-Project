#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

//declare all functions
char *read_file(unsigned long *size, char *file_name); 
int write_file(unsigned long size, char *output, char *filename); 
void encrypt(char *input_file, char *cipher_file, char *output_file); 
void decrypt(char *input_file, char *cipher_file, char *output_file); 
int Alpha(char c); 

/*Takes  a  reference  to  size  and  the  input  file  name,  and  returns  the 
allocated string that contains contents of the input file*/
char *read_file(unsigned long *size, char *file_name) { 
   //pointer,open,readfile
   FILE *fptr = fopen(file_name, "r"); 
   
   //read from the start to the end of file
   fseek(fptr, 0L, SEEK_END); 
   //current position of the file
   *size = ftell(fptr); 
   //sets to the beginning of the file 
   rewind(fptr);

   //error when opening a file
   if (fptr == NULL) { 
      printf("Error opening file"); 
      return NULL; 
   } 
   //allocate space for string
   char *input = malloc(*size); 

   //read file contents to allocated string 
   fread(input, *size, 1, fptr); 
   // close file 
   fclose(fptr); 
   //return string buffer 
   return input; 
} 
/*Takes  the  size  of  the  string  buffer  to  be  written  to  the  output  file 
and the filename, and returns the number of bytes written to the output file.*/
int write_file(unsigned long size, char *output, char *filename) { 
   //pointer and open file to write 
   FILE *fptr = fopen(filename, "w"); 

   //error message 
   if (fptr == NULL) { 
      printf("Error opening file"); 
   return -1; 
 } 
 //string buffer to the output file 
   int bytes_written = fwrite(output, size, 1, fptr); 
   // close file
   fclose(fptr); 
   // return the number of written bytes 
return bytes_written; 
} 
// function for encrypt to take lower and uppercase char/strings 
int Alpha(char c) { 
   if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) { 
   return 1; 
} else { 
   return 0; 
   } 
}
/*function  takes  an  input  file,  a  cipher_file  and  an  output  file,  encrypts 
contents in the input file, and writes the cipher factor and contents to the output 
file. */
void encrypt(char *input_file, char *cipher_file, char *output_file){ 
   unsigned long size; 
   // read file input contents 
   char *input = read_file(&size, input_file);

   //allocate for space for output 
   char *output = malloc(size); 
   // ask user for cipher factor integer 
   int k_cipher_Element; 
   printf("Enter cipher factor k : "); 
   scanf("%d", &k_cipher_Element); 
   
   // encrypt the input file refer to Alpha function
   //loop to encrypt file using caesar cypher 
   /*encrypt all alphabets by the alphabet rotation factor k, which means shift 
each  letter  by  k  number  of  letters.  If  the  shift  takes  you  past  the  end  of  the 
alphabet, just rotate back to the front of the alphabet*/
   for (int i = 0; i < size; i++) { 
   if (Alpha(input[i])) { 
      output[i] = (input[i] + k_cipher_Element - 'a') % 26 + 'a'; 
   } else { 
      output[i] = input[i]; 
      } 
   } 
   //write cipher contents to the output file
   write_file(size, output, output_file); 
   // write the cipher factor to the cipher file 
   FILE *fptr = fopen(cipher_file, "w"); 

   //error message 
   if (fptr == NULL) { 
      printf("Error opening file"); 
      return; 
   } else { 
      //print the cipher 
      fprintf(fptr, "%d", k_cipher_Element); 
   } 
   //free all allocated memory 
   free(input); 
   free(output); 
}/* 
* This function takes an input file, a cipher_file and an 
output file, decrypts 
contents in the output file, and writes decrypted contents
to the input file. 
*/ 
void decrypt(char *input_file, char *cipher_file, char *output_file){ 
   unsigned long size; 
   //call the read_file function to buffer encrypted contents from the output file 
   char *output = read_file(&size, output_file);
   unsigned long cipher_size; 
   //call the read_file function to get the rotation factor k from the cipher file 
   char *cipher = read_file(&cipher_size, cipher_file); 
    //changing strings into a integer value 
   int k_cipher_Element = atoi(cipher);
   // decrypt  encrypted  contents  back  to  original  contents 
   char *input = malloc(size); 
   for (int i = 0; i < size; i++) { 
      if (Alpha(output[i])) { 
         input[i] = (output[i] - k_cipher_Element - 'a') % 26 + 
         'a'; 
         } else { 
         input[i] = output[i];
      } 
   } 
   //write original contents to the input file
   write_file(size, input, input_file);
   //free() all allocated memory 
   free(input); 
   free(cipher); 
   free(output);
}
int main() { 
/* write a menu including 3 choices: encrypt file, decrypt file 
   and exit program, for user to use the program */ 
      char input_file[1000]; 
      char cipher_file[1000]; 
      char output_file[1000]; 
 // print menu 
   int choice = 0; 
   while (choice != 3) { 
      printf("Press 1: Encrypt file  ");
      printf("Press 2: Decrypt file  ");
      printf("Press 3: exit the program\n  ");
      // get user input 
      printf("Enter your choice: "); 
      scanf("%d", &choice); 
      // check user input 
   if (choice == 1) { 
      // encrypt file 
      printf("Enter a file name to be encrypted: "); 
      scanf("%s", input_file); 
      printf("Enter cipher file name : "); 
      scanf("%s", cipher_file); 
      printf("Enter a file name for the output file: "); 
      scanf("%s", output_file); 
      encrypt(input_file, cipher_file, output_file); 
   } else if (choice == 2) { 
      // decrypt file 
      printf("Enter in the encrypted File "); 
      scanf("%s", input_file); 
      printf("Enter cipher file name : "); 
      scanf("%s", cipher_file); 
      printf("Enter in Original document:  "); 
      scanf("%s", output_file); 
      decrypt(input_file, cipher_file, output_file); 

   } else if (choice == 3) { 
      // exit program 
      printf("Exiting program"); 
   } else { 
      // invalid input 
      printf("Invalid input try again \n"); 
      } 
   } 
   return 0; 
}