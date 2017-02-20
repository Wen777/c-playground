#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "rational_number_D0565617.h"

// Test case 1/2 + -1/3
//          1/2 + 1/3
//          1/3 + 1/2
//          1/3 + -1/2
Fraction fractionAddition(Fraction a, Fraction b) {
    a.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    a.denominator = a.denominator * b.denominator;
    ensureGcd(&a);
    return a;
};

Fraction fractionSubtraction(Fraction a, Fraction b) {
    a.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    a.denominator = a.denominator * b.denominator;
    ensureGcd(&a);
    return a;
}

Fraction fractionMultiplication(Fraction a, Fraction b) {
    a.numerator = a.numerator * b.numerator;
    a.denominator = a.denominator * b.denominator;
    ensureGcd(&a);
    return a;
}

Fraction fractionDivision(Fraction a, Fraction b) {
    if(a.numerator * b.numerator < 0 && b.numerator < 0) {
        a.numerator = a.numerator * -1;
        b.numerator = abs(b.numerator);
    }
    a.numerator = a.numerator * b.denominator;
    a.denominator = b.numerator * a.denominator;
    ensureGcd(&a);
    return a;
}

Fraction fractionAbs(Fraction a) {
    a.numerator = abs(a.numerator);
    a.denominator = abs(a.denominator);
    ensureGcd(&a);
    return a;
}

Fraction intsToFraction(int a, int b) {
    Fraction fraction;

    if(b < 0) {
        if(a * b < 0 ) {
            a = a * -1;
            b = abs(b);
        } else {
            a = abs(a);
            b = abs(b);
        }
    }

    fraction.numerator = a;
    fraction.denominator = b;
    ensureGcd(&fraction);
    return fraction;
}

Fraction intToFraction(int a) {
    Fraction fraction;
    fraction.numerator = a;
    fraction.denominator = 1;

    ensureGcd(&fraction);
    return fraction;
}

void PrintFraction(Fraction a) {
    printf("%d/%d\n", a.numerator, a.denominator);
}

void ensureGcd(Fraction *fraction) {
    int divisor = GCD(abs(fraction->numerator), abs(fraction->denominator));

    fraction->numerator = fraction->numerator / divisor;
    fraction->denominator = fraction->denominator / divisor;
}

// GCD
int GCD(int m, int n) {
    m = abs(m);
    n = abs(n);

    if (m%n == 0) {
        return n;
    } else {
        return GCD(n, m % n);
    }
}

