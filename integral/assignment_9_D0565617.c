#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define epsilon 0.000001 // Difference error.
#define PI 3.1415926535897

double a;

double Riemann_sum_area(double x, double b, double (*f)(double), int *T) {
  double interval; // Size of the partitioned interval.
  double point; // The middle point of each individual interval.
  double poly; // Value of evaluating the polynomial on point, P(point).
  double area; // Are of the covered area, Riemann sum of the current iteration.
  double last; // Riemann sum of the previous iteration.
  int i; // Loop variable.

  printf("b %lf x %lf \n", b, x);

  *T = 1;
  area = -1;
  last = -2;
  while (fabs(area-last)>epsilon) {
    interval = fabs(b - x) / *T; // Interval size.
    point = x + interval / 2.0; // Middle point of the first interval.
    last = area; // The area of the previous iteration.
    area = 0; // Initial area to zero.
    for (i=0; i<*T; i++) { // Compute bar area of all intervals.
      area += fabs((*f)(point) - (a * 0.5)) * interval; // Accumulate the area of Riemann sum.
      point += interval; // The middle point of the next interval.
    }
    // Outpu the number of intervals, interval size, and area of this iteration.
    printf("Number of intervals: %d, interval size: %8.6lf, area: %8.6lf\n", *T, interval, area);
    *T = *T * 2; // Double the number of partitioned intervals.
  }

  return area;  // Return the resulting area.
}

double area1_func1 (double point) {
    return sqrt((a * a)  -  (point * point  ) );
}

int main(void) {
  double b; // Interval (a, 0) and (b, 0).
  double area1 = 0, area2 = 0, area3 = 0;
  int T; // Number of the partitioned intervals.

  while (1) {
    printf("Enter the side of square a: ");
    scanf("%lg", &a); // Input the interval bound.
    if (a == 0) {
        break;
    }

    area1 = 4.0 * Riemann_sum_area(a / 2.0 , sqrt(3.0) * 0.5 * a , area1_func1, &T);
    area2 = (PI * pow(a, 2.0) - 2 * pow(a, 2.0)) - 2.0 * area1;
    area3 = pow(a, 2.0) - area1 - area2;
    printf("Area R1 %6.4lf, Area R2 %6.4lf, Area R3 %6.4lf %lf\n", area1, area2, area3, area1 + area2 + area3);
  }


  return 0;
}
