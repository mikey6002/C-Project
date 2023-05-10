#include <stdio.h>

int match_content(char *file1, char *file2) {
//pointer pointing to file..... 
//pointer f1 is pointing to file 1 
    FILE *f1 = fopen(file1, "r");
//pointer f2 is pointing to file 2
    FILE *f2 = fopen(file2, "r");
//logical and to see if they are the same upon the given conditionals 
    if (f1 && f2) {
        char c1, c2;
        while ((c1 = (char)getc(f1)) != EOF || (c2 = (char)getc(f2)) != EOF) {
            if (c1 >= 'a' && c1 <= 'z') {
                c1 -= 32;
            }
            if (c2 >= 'a' && c2 <= 'z') {
                c2 -= 32;
            }
            if (c1 != c2) {
//If the contents in C1 does not equal in C2----> my output will be 0 otherwise it will return 1. 
                return 0;
            }
        }
        return getc(f1) == EOF & getc(f2) == EOF;
    }
    return 1;
}

int main() {
    printf("%d\n", match_content("input1.txt", "input2.txt"));
    return 0;
}