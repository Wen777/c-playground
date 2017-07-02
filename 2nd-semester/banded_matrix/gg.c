/* LU-decomposition. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int min(int x, int y) {
  if (x<y) return x;
  else return y;
}

/* A: nxn matrix,
   L: nxn lower triangular matrix,
   U: nxn upper triangular matrix.
   Compute A=LU.
*/
void LU_decompose(int n, float A[100][100], float L[100][100], float U[100][100]) {
  int i, j, k;
    
  for (k=0; k<n; k++) { // To compute submatrix A(k+1).
    for (j=k; j<n; j++) U[k][j] = A[k][j]; // Compute elements of the k-th row of matrix U
    for (i=k; i<n; i++) L[i][k] = A[i][k] / A[k][k]; // Compute elements of the k-th column of matrix L
    for (i=k+1; i<n; i++) // Compute elements of submatrix A(k+1):
      for (j=k+1; j<n; j++) A[i][j] = A[i][j] - L[i][k] * U[k][j];
  }
}

int main(void) {
  float A[100][100], A1[100][100], L[100][100], U[100][100]; // Assume maximum 100 by 100 elements.
  int n; // Size of the square matrices.
  int check; // Flag to check the correctness of the program.
  int i, j, k; // Loop variables.
  
  srand(time(NULL)); // Seed of the random number generator.
  
  printf("Enter square matrix size n: "); // Input the matrix size.
  scanf("%d", &n);
    
  // Get values for the elements of matrix A.
  // Matrix element A[i][j], 0<A[i][j]<=1; A1[i][j] is the copy of A[i][j] for program verification.
  for (i=0; i<n; i++)
    for (j=0; j<n; j++) {A[i][j] = (rand() % 10000 + 1) / 10000.0; A1[i][j] = A[i][j];}
  
  printf("\nMatrix A:\n"); // Output matrix A.
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) printf("%8.4f ", A[i][j]);
    printf("\n");
  }
  
  LU_decompose(n, A, L, U); // Peform LU-decomposition. 
  
  printf("\nMatrix L:\n"); // Output matrix L.
  for (i=0; i<n; i++) {
    for (j=0; j<=i; j++) printf("%8.4f ", L[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix U:\n"); // Ouput matrix U.
  for (i=0; i<n; i++) {
    for (j=0; j<i; j++) printf("         "); // Do not print the lower triangular elements.
    for (j=i; j<n; j++) printf("%8.4f ", U[i][j]);
    printf("\n");
  }
  
  check = 1; // Intial flag to true. 
  for (i=0; i<n && check; i++)
    for (j=0; j<n && check; j++) {
      A[i][j] = 0;
      for (k=0; k<=min(i,j); k++) A[i][j] += L[i][k] * U[k][j]; // Compute A[i][j] for A<=LU 
      check = check && (fabs(A[i][j]-A1[i][j])<0.0001); // Compare A[i][j] and A1[i][j], allow error 0.0001.
    }
  
  if (check) printf("\nThe LU-decomposition program is correct.\n"); // The program is correct.
  else printf("\nThe LU-decomposition program is incorrect.\n"); // The program is incorrect.
  
  return 0; 
}
