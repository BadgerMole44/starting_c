#include <stdio.h>

/*
What? prompts for two integers using scanf preforms simple validation and displays if the integers are >, <, or =
*/

int main(void){
    int x;
    int y;
    
    printf("Type a number in the range -(2^31), (2^31)-1: ");                 // get the first number
    int result = scanf("%d", &x);                                             // scanf expects a pointer

    printf("%d\n", x);

    while (result == 0) {                                                     // validate the first number
        printf("Invalid Input\nType a number in the range -(2^31), (2^31)-1: ");   
        result = scanf("%d", &x);
    }

    printf("Type another number in the range -(2^31), (2^31)-1: ");           // get the second number
    result = scanf("%d", &y);

    while (result == 0) {                                                     // validate the second number
        printf("Invalid Input\nType another number in the range -(2^31), (2^31)-1: ");   
        result = scanf("%d", &y);
    }

    if (x > y) {                                                              // print comparison
        printf("%d is greater than %d.", x, y);
    } else if (x < y) {
        printf("%d is greater than %d.", y, x);
    } else {
        printf("%d and %d are equal.", x, y);
    }

    return 0;
}