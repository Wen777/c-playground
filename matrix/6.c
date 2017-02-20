/* Banded matrix multiplication. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Return the maximum value of x and y.
int max(int x, int y) {
  if (x>y) return x;
  else return y;
}

// Return the minimum value of x and y.
int min(int x, int y) {
  if (x<y) return x;
  else return y;
}

/* A: nxn matrix,
   B: nxn matrix,
   C: nxn matrix,
   ra: the lower bandwidth of matrix A,
   rb: the upper bandwidth of matrix A,
   sa: the lower bandwidth of matrix B,
   sb: the upper bandwidth of matrix B,
   ra+sa: the lower bandwidth of matrix C,
   rb+sb: the upper bandwidth of matrix C.
   Compute C=AB using banded matrix multiplication algorithm.
*/
void matrix_product_banded(int n, int ra, int rb, int sa, int sb,
                           int A[100][100], int B[100][100], int C[100][100]) {
  int i, j, k;
  // The three loops follow the indecies i, j, k given in the formula of banded matrix multiplication.
  for (i=0; i<n; i++) // 0 <= i <= n-1
    for (j=max(0,i-ra-rb); j<=min(n-1,i+sa+sb); j++) { // max(0,i-ra-rb) <= j <= <=min(n-1,i+sa+sb)
      C[i][j] = 0; // Initial c[i][j] to 0.
      // max(0, max(i-ra,j-sb)) <= k <= min(n-1,min(i+sa,j+rb))
      for (k=max(0, max(i-ra,j-sb)); k<=min(n-1,min(i+sa,j+rb)); k++) C[i][j] += A[i][k] * B[k][j];
    }
}

int main(void) {
  int A[100][100], B[100][100], C[100][100], C1[100][100]; // Assume maximum 100 by 100 elements.
  int n; // Size of square matrices.
  int ra, sa; // Lower bandwidth and upper bandwidth of matrix A.
  int rb, sb; // Lower bandwidth and upper bandwidth of matrix B.
  int i, j, k; // Loop variables.

  srand(time(NULL));

  printf("Enter matrix size n: "); // Input the size of square matrices.
  scanf("%d", &n);
  // Input lower bandwidth and upper bandwidth of matrix A.
  printf("\nEnter the lower bandwidth and upper bandwidth of matrix A, ra and sa: ");
  scanf("%d %d", &ra, &sa);
  // Input lower bandwidth and upper bandwidth of matrix A.
  printf("\nEnter the lower bandwidth and upper bandwidth of matrix B, rb and sb: ");
  scanf("%d %d", &rb, &sb);

   // Randomly generate elements of A, between 1 and 100.
  for (i=0; i<n; i++)
    for (j=max(0,i-ra); j<=min(n-1,i+sa); j++) A[i][j] = rand() % 100 + 1;

   // Randomly generate elements of B, between 1 and 100.
  for (i=0; i<n; i++)
    for (j=max(0,i-rb); j<=min(n-1,i+sb); j++) B[i][j] = rand() % 100 + 1;

  // Compute banded matrix multiplication.
  matrix_product_banded(n, ra, rb, sa, sb, A, B, C);

  printf("\nMatrix A:\n"); // Output non-zero elements of matrix A.
  for (i=0; i<n; i++) {
    printf("    ");
    for (j=0; j<max(0,i-ra); j++) printf("   "); // Print blanks for zero elements on the left-hand-side.
    for (j=max(0,i-ra); j<=min(n-1,i+sa); j++) printf("%2d ", A[i][j]); // Print non-zero elements.
    printf("\n");
  }

  printf("\nMatrix B:\n"); // Output non-zero elements of matrix B.
  for (i=0; i<n; i++) {
    printf("    ");
    for (j=0; j<max(0,i-rb); j++) printf("   "); // Print blanks for zero elements on the left-hand-side.
    for (j=max(0,i-rb); j<=min(n-1,i+sb); j++) printf("%2d ", B[i][j]); // Print non-zero elements.
    printf("\n");
  }

  printf("\nMatrix C:\n"); // Output non-zero elements of matrix C.
  for (i=0; i<n; i++) {
    printf("    ");
    for (j=0; j<max(0,i-ra-rb); j++) printf("      "); // Print blanks for zero elements on the left-hand-side.
    for (j=max(0,i-ra-rb); j<=min(n-1,i+sa+sb); j++) printf("%5d ", C[i][j]); // Print non-zero elements.
    printf("\n");
  }

  return 0;
}
