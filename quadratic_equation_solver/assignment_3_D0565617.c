#include <stdio.h>
#include <math.h>

// Input_1 (1, 5, 6), Output (-2, -3)
// (1, 0, 0) (0)
int main(void) {
    double a = 0, b = 0, c = 0, judge = 0;
    double real_part = 0.0, complex_part = 0.0;
    printf("Solving roots of equation a*X**2+b*X+c = 0 .\n");
    printf("Please enter three coefficients a, b, and c:");
    do {
    scanf("%lf %lf %lf", &a, &b, &c);
    } while(a == 0);

    printf("The multiple real root of equation ");

    // Two cases: real root, complex root
    judge = (b * b) - 4 * a *c;
    if (judge < 0) {
        // complex   
        if (a == 1) {
            printf("X**2");
        } else {
            printf("%6.4fX**2", a);
        }

        if (b > 0) {
            printf("+ %6.4fX", b);
        } else if (b < 0) {
            printf("%6.4fX", b);
        }

        if (c > 0) {
            printf("+ %6.4f", c);
        } else if (c < 0) {
            printf("- %6.4f", c);
        }
        real_part = -b  / (2.0 * a);
        complex_part =  sqrt(4 * a * c - b * b) / (2.0 * a);
        printf("= 0.0000 is %6.4f + %6.4fi and %6.4f - %6.4fi", real_part, complex_part, real_part, complex_part);

    } else {
        // real
        if (a == 1) {
            printf("X**2");
        } else {
            printf("%6.4fX**2", a);
        }

        if (b > 0) {
            printf("+ %6.4fX", b);
        } else if (b < 0) {
            printf("%6.4fX", b);
        }

        if (c > 0) {
            printf("+ %6.4f", c);
        } else if (c < 0) {
            printf("- %6.4f", c);
        }

        if (judge == 0.0) {
            if (b == 0) {
                printf("= 0.0000 is %6.4f", b / (2.0 * a) );
            } else {
                printf("= 0.0000 is %6.4f", (-b) / (2.0 * a) );
            }
        } else {
            printf("= 0.0000 is %6.4f and %6.4f", ((-1.0 * b ) + sqrt((b * b) - (4.0 * a * c))) / (2.0 * a), ((-1.0 * b ) - sqrt((b * b) - (4.0 * a * c))) / (2.0 * a) );
        }
    }
    
    //printf("a: %lf, b: %f, c: %lf", a, b, c);
    return 0;
}
