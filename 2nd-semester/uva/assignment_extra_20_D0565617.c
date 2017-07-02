#include<stdlib.h>
#include<stdio.h>

// D0565617 施文祥


// Solution 2
// Analytical approach
int main(void) {
    int input;
    while(scanf("%d", &input) != EOF) {
        // By analyzing the result, we can know the pattern of the exchange system
        // As a result, the answer would be celi(input * 1.5)
        printf("%d\n",input + input / 2);
    }

    return 0;
}
