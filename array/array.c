#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>


int get_valid_int(void);

int main(void) {
    const int N = 3;
    int scores[N];    // scores is declared as an array of integers of lenght 3. 3 * size of int = 24 bytes. scores is a pointer to the first byte.
    int sum = 0;

    for (int i = 0; i < N; i++) {                        // populate the scores arr and add to sum
        printf("Enter a score. (%i of %i): ", i+1, N);
        int score = get_valid_int();
        scores[i] = score;
        sum += score;
    }

    float average = (float) sum / N;

    printf("The average score of ");
    for (int i = 0; i < N; i++) {
        if (i < N - 1){
            printf("%i, ", scores[i]);
        } else {
            printf("and %i is: %.2f", scores[i], average);     // print to 2 decimal places
        }
    }
    return 1;
}
int get_valid_int(void) {
    const int MAX_INPUT_LENGTH = 12;  // the string representation of an integer is at most 12 bytes long "-2147483648\0"
    const int MIN_INT = -2147483648;
    const int MAX_INT = 2147483647;
    char in[MAX_INPUT_LENGTH];
    int valid = 0;
    char *endptr;
    int out;

    while (!valid) {
        valid = 1;

        fgets(in, MAX_INPUT_LENGTH, stdin);     // read chars to the arr pointed to by in till /n or MAX_INPUT_LENGTH - 1 chars have been read from the stdin (standar input) 
    
        int len = strlen(in);                   // strlen returns the length of the char arry excluding the null char.
    
        for (int i = 0; i < len - 1; i++) {         // validate that in is a negative or positive integer
            if (!isdigit(in[i]) && (i != 0 && in[i] != '-')) {
                valid = 0;
                printf("Invalid Input: Non-digit %s\nEnter Integer in the range -(2^31), ((2^31)-1): ", in);
            } 
        }

        if (valid) {
            errno = 0;
            long int value = strtol(in, &endptr, 10);               // string to long: *charArray, thisWillPointToLastConvertedChar, base10
            if  (errno == ERANGE) {                                 // out of range of the long
                valid = 0;
                printf("Invalid Input: out of range of long. %s\nEnter Integer in the range -(2^31), ((2^31)-1): ", in);
            } else if (value < MIN_INT || value > MAX_INT) {        // out of range
                valid = 0;
                printf("Invalid Input: out of range of int. %s\nEnter Integer in the range -(2^31), ((2^31)-1): ", in);
            } else {
                out = (int) value;
            }
        }
    }
    return out;
}

