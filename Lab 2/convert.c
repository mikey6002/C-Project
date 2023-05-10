/*
    Number converter
    Menu
    Convert between integer, binary and hexadecimal
    This program should accept numeric values in hexadecimal,
    decimal and binary formats as:
        Hex 0x0 to 0xFFFFFFFF
        Dec 0 to 4294967295
        Bin b0 to b11111111111111111111111111111111
    After a value is input the code in main will interpret the
    data types above an process the conversion to an unsigned
    int.  The unsigned int will be used to convert the input to
    strings containing hexadecimal and binary strings.
*/
#include <stdio.h>
#include <string.h>
//int input_to_decimal(char *input);
unsigned int bin_to_uint(char *input);
unsigned int hex_to_uint(char *input);
unsigned int dec_to_uint(char *input);
void uint_to_hex(unsigned int n, char *output);
void uint_to_bin(unsigned int n, char *output);
int error = 0;

int main(){
    char input[50];
    unsigned int n = 0;
    char output[50];
    // Write code here to test your functions
    // Uncomment code below when done
    printf("Enter a binary, decimal or hexadecimal number\n");
   /* printf("convert > ");
    gets(input);
    // Detect input data type
    // Hexadecimal
    if(input[0] == '0' && input[1] == 'x'){
        n = hex_to_uint(input);
    }
    // Decimal
    else if(input[0] >= '0' && input[0] <= '9'){
        n = dec_to_uint(input);
    }
    // Binary
    else if(input[0] == 'b'){
        n = bin_to_uint(input);
    }
    // Unknown
    else{
        printf("ERROR: Unknown data type: %s\n", input);
    }
    // Print results
    printf("The decimal value of %s is %u\n", input, n);
    uint_to_hex(n, output);
    printf("The hexadecimal value of %s is %s\n", input, output);
    uint_to_bin(n, output);
    printf("The binary value of %s is %s\n", input, output);
*/
    return 0;
}
/*
    This function converts the value part of the hex
    string to an unsigned integer value.  The first
    two chars are 0x, which tells that the string is
    in hex.  Start processing the value at index 2 until
    the null, calculating the int value as you would on
    paper.  Try on paper first.
*/
// Convert a hexadecimal char array to uint
unsigned int hex_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
    int i =0; 

    // Declare and set multiplier to 1
    // Declare iterator
    // Loop through value part of input string
        // If between 0 and 9 add 0 to 9 to res with multiplier
        // If between A and F add 10 to 15 to res with multiplier
        // Error - exit
        // Advance multiplier to next position value
    return res;
}
/*
    Copy hex_to_uint() and modify for decimal input.
*/
// Convert a unsigned integer char array to uint
unsigned int dec_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
    return res;
}
/*
    Copy dec_to_uint() and modify for binary input.
*/
// Convert a binary char array to unsigned int
unsigned int bin_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
    
    return res;
}
/*
    This function converts from unsigned int to a hex
    char array.  Try this on paper before coding.
*/
// Convert a unsigned integer char array to hexadecimal
void uint_to_hex(unsigned int n, char *output){
    // Declare a uint for remainder
    // Declare an int for division
    // Declare a char array buffer
    // Use a loop to generate a hex string - string will be reverse
    // Get last hex char
    // Put null at end of buffer
    // Copy 0x to output string
    // Copy chars from buffer in reverse order to output string
    return;
}
/*
    Copy uint_to_hex() and modify for bin
*/
// Convert a unsigned integer char array to binary
void uint_to_bin(unsigned int n, char *output){
    return;
}