#include<stdlib.h>
#include<stdio.h>
// D0565617 施文祥 David

// Solution 1
int main(void) {
    int input;
    int bestResult;

    // load data
    while(scanf("%d", &input) == 1) {
        // show homany bottoles of cola are available
        if (input <= 1) {
            printf("%d\n", input);
        } else {
            // drink all the cola first.
            bestResult = input;

            // if one empty bottle left, skip it
            while( input != 1  ) {
                // borrow a bottle from friend
                if ( input == 2 ) {
                    input++;
                }
                // count how many bottles of cola drunk
                bestResult = bestResult + input / 3;
                // left bottles + exchanged bottles of cola
                input = input % 3 + input / 3;
            }
            printf("%d\n", bestResult);
        }
    }
    return 0;
}
