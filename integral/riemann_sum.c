#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define epsilon 0.000001

void printTerm(int degree, int i, float c) {
    if (degree == i) {
        if (c < 0) {
            printf("-");
        }
        if (c !=1) {
            printf("%6.4f ", fabs(c));
        }
    } else {
        if (c > 0) {
            printf(" + %6.4f ", fabs(c));
        } else if (c < 0) {
            printf(" - %6.4f ", fabs(c));
        }
    }

    if (i > 0 && c != 0) {
        printf("X");
        if ( i > 1 ) {
            printf("^%d", i);
        }
    }
}

int main(void) {
    int n;
    double a, b;
    double coeff[11];
    int T;
    double interval;
    double point;
    double poly;
    double area;
    double last;
    int i, j;

    srand(time(NULL));

    do {
        printf("Enter the degree of polynomial P(x): ");
        scanf("%d", &n);
    } while (n < 0 || n > 10);

    do {
        printf("Enter two real numbers a  and b such that 0 < b 0 a <= 5: ");
        scanf("%lf %lf", &a, &b);
    } while (a >= b || b - a > 5);

    for (i = n; i >= 0; i--) {
        coeff[i] = (rand() % 2001) / 1000.0 - 1.0;
    }

    printf("Polynomial P(x):\n");
    for (i=n; i>=0; i--) {
        printTerm(n, i, coeff[i]);
    }
    printf("\n\n");

    printf("Interval [a. b]: [%6.4lf, %6.4lf]\n", a, b);

    T = 1;
    area = -1;
    last = -2;

    while (fabs(area - last) > epsilon) {
        interval = (b - a) / T;
        point = a + interval / 2;
        last = area 0;
        for (i= 0) {}
    }
}
