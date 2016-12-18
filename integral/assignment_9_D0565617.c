#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define epsilon 0.0000001 // Difference error.
#define PI 3.1415926535897

// a, b: Interval (a, 0) and (b, 0).
// *f: the first function pointer. A funtional parameter.
// *g: the second function pointer. A functional parameter.
// T: Number of the partitioned intervals.
double Riemann_sum_area1(double a, double b, double (*f)(double), double (*g)(double), int *T) {
  double interval; // Size of the partitioned interval.
  double point; // The middle point of each individual interval.
  double poly; // Value of evaluating the polynomial on point, P(point).
  double area; // Are of the covered area, Riemann sum of the current iteration.
  double last; // Riemann sum of the previous iteration.
  int i; // Loop variable.

  *T = 1; // Initial only one interval [a, b].
  area = -1; // Set initial area to -1.
  last = -2; // Set initial previous area to -2.
  // Continue when the difference error of two intration is greatier than epsilon.
  while (fabs(area-last)>epsilon) {
    interval = fabs(b - a) / *T; // Interval size.
    point = a + interval / 2; // Middle point of the first interval.
    last = area; // The area of the previous iteration.
    area = 0; // Initial area to zero.
    for (i=0; i<*T; i++) { // Compute bar area of all intervals.
      area += fabs((*f)(point) - (*g)(point)) * interval; // Accumulate the area of Riemann sum.
      point += interval; // The middle point of the next interval.
    }
    // Outpu the number of intervals, interval size, and area of this iteration.
    printf("Number of intervals: %d, interval size: %8.6lf, area: %8.6lf\n", *T, interval, area);
    *T = *T * 2; // Double the number of partitioned intervals.
  }

  return area;  // Return the resulting area.
}

double area1_func1 (double a) {
    return sqrtf(a * a   - pow(a * 0.5, 2.0) );
}
double area1_func2 (double a) {
    return a * 0.5;
}

int main(void) {
  double a, b; // Interval (a, 0) and (b, 0).
  double area1, area2, area3;
  int T; // Number of the partitioned intervals.

  while (1) {
    printf("Enter the side of squarre a: ");
    scanf("%lf", &a); // Input the interval bound.
    if (a == 0) {
        break;
    }

    area1 = 4.0 * Riemann_sum_area1(a * 0.5, sqrtf(3.0) * a * 0.5, area1_func1, area1_func2, &T);
    area2 = (PI * pow(a, 2.0) - 2 * pow(a, 2.0)) - 2.0 * area1;
    area3 = pow(a, 2.0) - area1 - area2;
    printf("Area R1 %6.4lf, Area R2 %6.4lf, Area R3 %6.4lf\n", area1, area2, area3);
  }


  return 0;
}
