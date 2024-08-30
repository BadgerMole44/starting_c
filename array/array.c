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
    long long int sum = 0;

    for (int i = 0; i < N; i++) {                        // populate the scores arr and add to sum
        printf("Enter a score. (%i of %i): ", i+1, N);
        int score = get_valid_int();
        scores[i] = score;
        sum += score;
        printf("    Sum = %lli\n", sum);
    }

    double average = (double) sum / N;

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
    const int MAX_INPUT_LENGTH = 12;     // the string representation of an integer is at most 11 bytes long "-2147483648\n" excluding the null char
    const int MIN_INT = -2147483648;
    const int MAX_INT = 2147483647;
    char in[MAX_INPUT_LENGTH];
    int valid = 0;
    char *endptr;
    int out;

    while (!valid) {
        valid = 1;

        /*
        Beware fgets(buffer, n, stream): Ensures proper string termination. reads up to n - 1 chars. Chars in the input beyond n-1 are left in 
        the input buffer. So, the next time fgets is called it reads from the chars in the leftover input buffer. Clear the buffer input after 
        calling to prevent this.
        */
        fgets(in, MAX_INPUT_LENGTH, stdin);

        int in_len = strlen(in);        // Strlen returns the length of the char arry excluding the null char.
        int too_long = 0;

        if (in[in_len - 1] =='\n') {    // if there is a \n in the input then there are no chars remaining in the input buffer.
            in[strcspn(in,"\n")] = 0;   
            in_len --;
        } else {                        // if there is no \n in the input then there are chars remaining in the buffer.
            int ch;                     
            while ((ch = getchar()) != '\n' && ch != EOF) {
                if (too_long == 0) {
                    too_long = 1;
                }
            }
        }
        
        if (too_long) {
            valid = 0;
            printf("Invalid Input: Input too long. Expected at most 11 chars \nEnter Integer in the range -(2^31), ((2^31)-1): ", in);
        }

        if (valid) {
            printf("    Entered '%s' \n", in);
            for (int i = 0; i < in_len; i++) {                                      // validate that in is a negative or positive integer 
                if (!isdigit(in[i])) {
                    if ((in[i] == '-' && i == 0)) {
                        if (!(in_len > (i + 1))) {
                            valid = 0;
                            printf("Invalid Input: Non-digit %s\nEnter Integer in the range -(2^31), ((2^31)-1): ", in);
                            break;
                        }
                    } else {
                        valid = 0;
                        printf("Invalid Input: Non-digit %s\nEnter Integer in the range -(2^31), ((2^31)-1): ", in);
                        break;
                    }
                }
            }
        }

        if (valid) {
            errno = 0;
            long long int value = strtol(in, &endptr, 10);               // string to long: *charArray, thisWillPointToLastConvertedChar, base10
            if  (errno == ERANGE) {                                 // out of range of the long
                valid = 0;
                printf("Invalid Input: out of range of int. %s\nEnter Integer in the range -(2^31), ((2^31)-1): ", in);
            } else if (value < MIN_INT || value > MAX_INT) {        // out of range
                valid = 0;
                printf("Invalid Input: out of range of int. %s\nEnter Integer in the range -(2^31), ((2^31)-1): ", in);
            } else {
                out = value;
            }
        }
    }
    return out;
}

