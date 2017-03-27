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

/* A: pointer to nxn banded matrix,
   B: pointer to nxn banded matrix,
   C: pointer to nxn banded matrix,
   ra: the lower bandwidth of matrix A,
   rb: the upper bandwidth of matrix A,
   sa: the lower bandwidth of matrix B,
   sb: the upper bandwidth of matrix B,
   ra+sa: the lower bandwidth of matrix C,
   rb+sb: the upper bandwidth of matrix C.
   Compute C=AB using banded matrix multiplication algorithm.
*/
void matrix_product_banded(int n, int ra, int rb, int sa, int sb,
                           int **A, int **B, int **C) {
  int i, j, k; // Loop variable.
  // The three loops follow the indecies i, j, k 
  // given in the formula of banded matrix multiplication.
  for (i=0; i<n; i++)
    // max(0,i-ra-rb) <= j <= <=min(n-1,i+sa+sb)
    for (j=max(0,i-ra-rb); j<=min(n-1,i+sa+sb); j++) { 
      C[i][j-max(0,i-ra-rb)] = 0; // Initial c[i][j] to 0.
      // max(0, max(i-ra,j-sb)) <= k <= min(n-1,min(i+sa,j+rb))
      for (k=max(0, max(i-ra,j-sb)); k<=min(n-1,min(i+sa,j+rb)); k++)
        // Each row of matrix A, B, and C are shift i-rx to the left, 
        // where rx is the lower bandwidth A, B, or C, if i-rx>0.     
        C[i][j-max(0,i-ra-rb)] += A[i][k-max(0,i-ra)] * B[k][j-max(0,k-rb)];
    }
}

int main(void) {
  int **A, **B, **C; // Pointers of two-dimensional arrays.
  int n; // Size of square matrices.
  int ra, sa; // Lower bandwidth and upper bandwidth of matrix A.
  int rb, sb; // Lower bandwidth and upper bandwidth of matrix B.
  int i, j, k; // Loop variables.
  
  srand(1); // Seed of the random number generator.
  
  printf("Enter matrix size n: "); // Input the size of square matrices.
  scanf("%d", &n); 
  // Input lower bandwidth and upper bandwidth of matrix A.
  printf("\nEnter the lower bandwidth and upper bandwidth of matrix A, ra and sa: ");
  scanf("%d %d", &ra, &sa); 
  // Input lower bandwidth and upper bandwidth of matrix A.
  printf("\nEnter the lower bandwidth and upper bandwidth of matrix B, rb and sb: ");
  scanf("%d %d", &rb, &sb); 
  
  // Allocate dynamic memory for matrices A, B, and C.
  A = (int **) malloc(sizeof(int*) * n); // Pointers to rows of matrix A.
  for (i=0; i<n; i++) A[i] = (int *) malloc(sizeof(int) * (min(i, ra)+1+min(n-1-i, sa))); // Rows of banded matrix A.
  B = (int **) malloc(sizeof(int*) * n); // Pointers to rows of matrix B.
  for (i=0; i<n; i++) B[i] = (int *) malloc(sizeof(int) * (min(i, rb)+1+min(n-1-i, sb))); // Rows of banded matrix B.
  C = (int **) malloc(sizeof(int*) * n); // Pointers to rows of matrix C.
  for (i=0; i<n; i++) C[i] = (int *) malloc(sizeof(int) * (min(i, ra+rb)+1+min(n-1-i, sa+sb))); // Rows of banded matrix C.
  
    
   // Randomly generate elements of A, between 1 and 100.
  for (i=0; i<n; i++)
    for (j=max(0,i-ra); j<=min(n-1,i+sa); j++)
      // If the i>ra, the i-th row is shift i-ra position to the left.
      A[i][j-max(0,i-ra)] = rand() % 100 + 1; 
    
   // Randomly generate elements of B, between 1 and 100.
   for (i=0; i<n; i++)
      // If the i>rb, the i-th row is shift i-rb position to the left.
    for (j=max(0,i-rb); j<=min(n-1,i+sb); j++) B[i][j-max(0,i-rb)] = rand() % 100 + 1;
    
  // Compute banded matrix multiplication.
  matrix_product_banded(n, ra, rb, sa, sb, A, B, C);
  
  // Output banded matrix A.
  printf("\nMatrix A:\n");
  for (i=0; i<n; i++) {
    printf("    ");
    // If the i>ra, patch i-ra blanks for zero elements..
    for (j=0; j<max(0,i-ra); j++) printf("    ");
    for (j=max(0,i-ra); j<=min(n-1,i+sa); j++) printf("%3d ", A[i][j-max(0,i-ra)]);
    printf("\n");
  }
  
  // Output banded matrix B.
  printf("\nMatrix B:\n");
  for (i=0; i<n; i++) {
    printf("    ");    
    // If the i>sa, patch i-sa blanks for zero elements.
    for (j=0; j<max(0,i-rb); j++) printf("    ");
    for (j=max(0,i-rb); j<=min(n-1,i+sb); j++) printf("%3d ", B[i][j-max(0,i-rb)]);
    printf("\n");
  }
  
  // Output banded matrix C.
  printf("\nMatrix C:\n");
  for (i=0; i<n; i++) {
    printf("    ");
    // If the i>ra+ba, patch i-ra-ba blanks for zero elements.
    for (j=0; j<max(0,i-ra-rb); j++) printf("       ");
    for (j=max(0,i-ra-rb); j<=min(n-1,i+sa+sb); j++) printf("%6d ", C[i][j-max(0,i-ra-rb)]);
    printf("\n");
  }
  
  // Deallocate memory space of matrices A, B, and C 
  for (i=0; i<n; i++) {free(A[i]); free(B[i]); free(C[i]);}
  free(A);
  free(B);
  free(C);
  
  return 0; 
}
