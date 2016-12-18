#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define epsilon 0.000001 // Difference error.

// The top half of the circle of radius 10.
double upper_circle(double x) {
  return sqrt(10.0 * 10.0 - x * x); // (10^2 - x^2)^(1/2)
}

// The bottom half of the circle of radius 10.
double lower_circle(double x) {
  return -sqrt(10.0 * 10.0 - x * x); // -(10^2 - x^2)^(1/2)
}

// a, b: Interval (a, 0) and (b, 0).
// *f: the first function pointer. A funtional parameter.
// *g: the second function pointer. A functional parameter.
// T: Number of the partitioned intervals.
double Riemann_sum(double a, double b, double (*f)(double), double (*g)(double), int *T) {
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

int main(void) {
  double a, b; // Interval (a, 0) and (b, 0).
  double area;
  int T; // Number of the partitioned intervals.
  
  printf("Enter two real numbers a and b: ");
  scanf("%lf %lf", &a, &b); // Input the interval bound.

  // Computer the area covered by two vertical lines x=a and x=b and the curves between 
  // the functions of circles above the X-axis below the X-axis.
  area = Riemann_sum(a, b, upper_circle, lower_circle, &T);
  
  printf("\nThe number of intervals: %d\n", T/2); // Output total number of intervals.
  // Output the final area.
  printf("Area of polynomial P(x) between (%6.4lf, 0.0) and (%6.4lf, 0.0): %8.6lf\n", a, b, area);
  
  return 0;
}
