#include <stdlib.h>
#include <stdio.h>

#include "rational_number_D0565617.h"

int main(void) {
    int first, last;
    Fraction a, b, c, d, ans;

    while(1) {
        printf("Enter the numerator and denominator of a: ");
        scanf("%d %d", &first, &last);
        a = intsToFraction(first, last);
        printf("Rational number a: ");
        PrintFraction(a);


        printf("Enter the numerator and denominator of b: ");
        scanf("%d %d", &first, &last);
        b = intsToFraction(first, last);
        printf("Rational number b: ");
        PrintFraction(b);

        printf("Enter the numerator and denominator of c: ");
        scanf("%d %d", &first, &last);
        c = intsToFraction(first, last);
        printf("Rational number c: ");
        PrintFraction(c);

        printf("Enter the numerator and denominator of d: ");
        scanf("%d %d", &first, &last);
        d = intsToFraction(first, last);
        printf("Rational number d: ");
        PrintFraction(d);

        printf("a + b = ");
        PrintFraction(fractionAddition(a, b));

        printf("a - b = ");
        PrintFraction(fractionSubtraction(a, b));

        printf("a * b = ");
        PrintFraction(fractionMultiplication(a, b));

        printf("a / b = ");
        PrintFraction(fractionDivision(a, b));

        printf("|a| = ");
        PrintFraction(fractionAbs(a));

        printf("a * |d -b| - (b + c / a) / |b + a - c * d| = ");

        ans = fractionAbs(fractionSubtraction(fractionAddition(b, a), fractionMultiplication(c, d)));
        ans = fractionDivision(fractionAddition(b, fractionDivision(c, a)), ans);
        ans = fractionSubtraction(fractionMultiplication(a, fractionAbs(fractionSubtraction(d, b))), ans);
        PrintFraction(ans);
    }
    return 0;
}
