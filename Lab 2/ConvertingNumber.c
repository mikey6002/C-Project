/*

Number converter

Menu
Convert between integer, binary, octal and hexadecimal

This program should accept numeric values in hexadecimal,
decimal, octal and binary formats as:

Hex 0x0 to 0xFFFFFFFF
Dec 0 to 4294967295
Oct o0 to o37777777777
Bin b0 to b11111111111111111111111111111111

After a value is input the code in main will interpret the
data types above an process the conversion to an unsigned
int. The unsigned int will be used to convert the input to
strings containing hexadecimal, octal and binary strings.

*/

#include<stdio.h>
#include<string.h>

#define GET_HEX_VAL(ch) ((ch >= 'a' && ch <= 'f') ? (ch - 'a' + 10) : ((ch >= 'A' && ch <= 'F') ? (ch - 'A' + 10) : -1))
#define HEX_CHAR_TO_UINT(ch) ((ch>='0' && ch<='9') ? (ch-0x30) : GET_HEX_VAL(ch))
#define OCT_CHAR_TO_UINT(ch) ((ch>='0' && ch<='7') ? (ch-0x30) : -1)
#define BIN_CHAR_TO_UINT(ch) ((ch=='0' || ch=='1') ? (ch-0x30) : -1)
#define DEC_CHAR_TO_UINT(ch) ((ch>='0' && ch<='9') ? (ch-0x30) : -1)
#define HEX_DIGIT "0123456789ABCDEF"
#define OCT_DIGIT "01234567"
#define BIN_DIGIT "01"

//int input_to_decimal(char *input);
unsigned int bin_to_uint(char *input);
unsigned int oct_to_uint(char *input);
unsigned int hex_to_uint(char *input);
unsigned int dec_to_uint(char *input);
void uint_to_hex(unsigned int n, char *output);
void uint_to_oct(unsigned int n, char *output);
void uint_to_bin(unsigned int n, char *output);
unsigned int power(int base, int exponent);
void strrev(char *string);

int error = 0;


int main(){

char input[50];
unsigned int n = 0;
char output[50];

// Write code here to test your functions
// Uncomment code below when done
// Line 57-82 code were given 
printf("Enter a binary, octal, decimal or hexadecimal number\n");
printf("convert > ");
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
// Octal to test my code further 
else if(input[0] == 'o'){
    n = oct_to_uint(input);
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
// Prints out the converion of each result
// I have octal to test code 
printf("The decimal value of %s is %u\n", input, n);
uint_to_hex(n, output);
printf("The hexadecimal value of %s is %s\n", input, output);
uint_to_oct(n, output);
printf("The octal value of %s is %s\n", input, output);
uint_to_bin(n, output);
printf("The binary value of %s is %s\n", input, output);

return 0;
}


/*
This function converts the value part of the hex
string to an unsigned integer value. The first
two chars are 0x, which tells that the string is
in hex. Start processing the value at index 2 until
the null, calculating the int value as you would on
paper. Try on paper first.
*/
// Convert a hexadecimal char array to uint
unsigned int hex_to_uint(char *input){
// Declare result and set to zero
unsigned int res = 0;
// Declare and set multiplier to 1

// Declare iterator

// Loop through value part of input string

// If between 0 and 9 add 0 to 9 to res with multiplier

// If between A and F add 10 to 15 to res with multiplier

// Error - exit

// Advance multiplier to next position value
int i = 0, temp;
for(i=strlen(input)-1; i>=2; i--){ //Loop from end and try adding the hex char value into unsigned int
    if ( -1 == (temp = HEX_CHAR_TO_UINT(input[i])))
{// check user if it is a valid hexadecimal number 
        printf("Invalid hex value\n");
return 0;
}
res += (temp * power(16, (strlen(input)-i-1))); //Add result with its exact base value
}
return res;
}


/*
Copy hex_to_uint() and modify for decimal input.
*/
// Convert a unsigned integer char array to uint
unsigned int dec_to_uint(char *input){
// Declare result and set to zero
unsigned int res = 0;
int i = 0, temp;
for(i=strlen(input)-1; i>=0; i--){
    if ( -1 == (temp = DEC_CHAR_TO_UINT(input[i]))) {// Checks if the user input is a decmal 
        printf("Invalid decimal value\n");
return 0;
}
res += (temp * power(10, (strlen(input)-i-1)));
}
return res;
}


/*
Copy dec_to_uint() and modify for octal input.
*/
// Convert a octal char array to uint
// This prt is to convert octal char to unsignint
unsigned int oct_to_uint(char *input){
// Declare result and set to zero
unsigned int res = 0;
int i = 0, temp;
for(i=strlen(input)-1; i>=1; i--){
    if ( -1 == (temp = OCT_CHAR_TO_UINT(input[i]))){
        printf("Invalid Octal value\n");
        return 0;
}
res += (temp * power(8, (strlen(input)-i-1)));
}

return res;
}


/*
Copy oct_to_uint() and modify for binary input.
*/
// Convert a binary char array to unsigned int
unsigned int bin_to_uint(char *input){
// Declare result and set to zero
unsigned int res = 0;
int i = 0, temp;
// added forloop to convert user binary chart into unisign char
for(i=strlen(input)-1; i>=1; i--){
    if ( -1 == (temp = BIN_CHAR_TO_UINT(input[i]))){ // tests uf the user input is a correct binary value 
        printf("Invalid binary value\n");
        return 0;
}
res += (temp * power(2, (strlen(input)-i-1)));
}

return res;
}


/*
This function converts from unsigned int to a hex
char array. Try this on paper before coding.
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

memset(output, 0, 50); //Make sure to initialize to null before passing, in order to avoid unexpected output.
int i=0;
while(n) { //Until the number is not zero, continue adding hex digit into string
    output[i++] = HEX_DIGIT[n%16]; //Get the hex digit into the string
    n/=16;
}
strcat(output, "x0"); //Add "x0" at end of the string
strrev(output); //Perform string reverse and get the result
return;
}


/*
Copy uint_to_hex() and modify for octal
*/
// Convert a unsigned integer char array to octal
// Again tried octal to have a better understanding 
void uint_to_oct(unsigned int n, char *output){

memset(output, 0, 50); //initialize to null before passing, in order to avoid unexpected output.
int i=0;
while(n){
    output[i++] = OCT_DIGIT[n%8];
    n/=8;
}
strcat(output, "o");
strrev(output);

return;
}


/*
Copy uint_to_oct() and modify for binary
This Again was practice you cn ignore if you want 
*/
// Convert a unsigned integer char array to binary
void uint_to_bin(unsigned int n, char *output){

memset(output, 0, 50); //initialize to null before passing, in order to avoid unexpected output.
int i=0;
char ch;
while(n){
    output[i++] = BIN_DIGIT[n%2];
    n/=2;
}
strcat(output, "b");
strrev(output);
return;
}

unsigned int power(int base, int exponent) {
int result = 1;
while (exponent != 0){
    result *= base;
    --exponent;
}
return result;
}

void strrev(char *string){
    int i = 0;
    int j = strlen(string) - 1;
    char temp;

    while (i < j) {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
        i++;
        j--;
    }
}