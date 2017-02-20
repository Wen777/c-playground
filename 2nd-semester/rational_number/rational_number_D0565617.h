typedef struct {
   int numerator;
   int denominator;
   int positive;
} Fraction;

// Addition
Fraction fractionAddition(Fraction a, Fraction b);

// Subtraction
Fraction fractionSubtraction(Fraction a, Fraction b);

// Multiplication
Fraction fractionMultiplication(Fraction a, Fraction b);

// Division
Fraction fractionDivision(Fraction a, Fraction b);

// Absolute value
Fraction fractionAbs(Fraction a);

// Rational conversion from two integers
Fraction intsToFraction(int a, int b);

// Rational conversion from an integer:
Fraction intToFraction(int a);

// Print a rational number.
void PrintFraction(Fraction a);

void ensureGcd(Fraction *fraction);

int GCD(int m, int n);
