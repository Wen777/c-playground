#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "rational_number_D0565617.h"

// gcd
int gcd(int m, int n) {
    m = abs(m);
    n = abs(n);

    if (m%n == 0) {
        return n;
    } else {
        return gcd(n, m % n);
    }
}
void ensureGcd(Fraction *fraction) {
    int divisor = gcd(abs(fraction->numerator), abs(fraction->denominator));

    fraction->numerator = fraction->numerator / divisor;
    fraction->denominator = fraction->denominator / divisor;
}

// validFraction if is validate fraction return 1; else return 0;
int validFraction(Fraction *fraction) {
    if(fraction->denominator == 0) {
        fraction->numerator = 0;
        fraction->denominator = 1;
        return 0;
    }

    return 1;
}

Fraction fractionAddition(Fraction a, Fraction b) {
    a.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    a.denominator = a.denominator * b.denominator;

    if(validFraction(&a)){
        ensureGcd(&a);
    };
    return a;
};

Fraction fractionSubtraction(Fraction a, Fraction b) {
    a.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    a.denominator = a.denominator * b.denominator;

    if(validFraction(&a)){
        ensureGcd(&a);
    };
    return a;
}

Fraction fractionMultiplication(Fraction a, Fraction b) {
    a.numerator = a.numerator * b.numerator;
    a.denominator = a.denominator * b.denominator;

    if(validFraction(&a)){
        ensureGcd(&a);
    };
    return a;
}

Fraction fractionDivision(Fraction a, Fraction b) {
    if(a.numerator * b.numerator < 0 && b.numerator < 0) {
        a.numerator = a.numerator * -1;
        b.numerator = abs(b.numerator);
    }
    a.numerator = a.numerator * b.denominator;
    a.denominator = b.numerator * a.denominator;

    if(validFraction(&a)){
        ensureGcd(&a);
    };
    return a;
}

Fraction fractionAbs(Fraction a) {
    a.numerator = abs(a.numerator);
    a.denominator = abs(a.denominator);

    if(validFraction(&a)){
        ensureGcd(&a);
    };
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
    if(validFraction(&fraction)){
        ensureGcd(&fraction);
    };
    return fraction;
}

Fraction intToFraction(int a) {
    Fraction fraction;
    fraction.numerator = a;
    fraction.denominator = 1;

    if(validFraction(&fraction)){
        ensureGcd(&fraction);
    };
    return fraction;
}

void PrintFraction(Fraction a) {
    printf("%d/%d\n", a.numerator, a.denominator);
}

