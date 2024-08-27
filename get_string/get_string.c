#include <stdio.h>

int main(void){
    /*
    In C strings are character arrays.
    A char is 1 BYTE so char var[x] reserves sizeof(char) * x bytes for the var.
    This is contigiuos memory.
    name is a pointer to the start of the char array.
    */
    char name[31];                                                          // name is an array of chars with a size of 31.
    printf("Hi what's your name?(Type a maximum of 30 characters): ");

    /*
    scanf reads the input and returns the number of input items successfully matched and assigned.
    %30s: reads up to 30 chars into name leaving space for null char \0.
    scanf automatically adds the null char at the end.
    scanf expects a pointer to where to store the scanned input.
    */
    int result = scanf("%30s", name);  

    if (result == 1) {
        printf("Hello, %s\n", name);
    } else {
        printf("Failed fo read a string.\n");
    }
    
    return 0;
}