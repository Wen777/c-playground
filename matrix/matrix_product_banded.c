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

void printMatrix(int size,int matrix[100][100]){
    int i, j;
    for(i = 0; i < size; i++ ) {
        for(j= 0; j < size; j ++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void product(int size, int A[100][100], int B[100][100], int C[100][100], int ra, int sa, int rb, int sb) {
    int i, j, k;
    for(i = 0; i < size; i ++) {
        for(j = max(0, i - ra - rb); j <= min(size-1, i + sa + sb); j++){
            C[i][j] = 0;
            for(k = max(0, max(i-ra, j-sb)); k <= min(size-1, min(i+sa, j+rb)); k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_product_banded(int n, int ra, int rb, int sa, int sb, int A[100][100], int B[100][100], int C[100][100]) {
      int i, j, k;
        for (i=0; i<n; i++) // 0 <= i <= n-1
            for (j=max(0,i-ra-rb); j<=min(n-1,i+sa+sb); j++) { // max(0,i-ra-rb) <= j <= <=min(n-1,i+sa+sb)
                C[i][j] = 0; // Initial c[i][j] to 0.
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
  printf("Enter lower band and upper band of A: ");
  scanf("%d %d", &ra, &sa);

  printf("Enter lower band and upper band of B: ");
  scanf("%d %d", &rb, &sb);

  srand(10);
  // init upper band matrix
  for(i = 0; i < n; i ++) {
      for(j = max(0, i - ra); j <= min(n-1, i + sa); j ++){
          A[i][j] = rand() % 10 + 1;
      }
  }

  for(i = 0; i < n; i++) {
      for(j = max(0, i - rb); j <= min(n-1, i+ sb); j ++){
          B[i][j] = rand() % 10 + 1;
      }
  }

  printf("Matrix A\n");
  printMatrix(n, A);
  printf("\n");

  printf("Matrix B\n");
  printMatrix(n, B);
  printf("\n");

  // init lower band matrix
  // product
  product(n, A, B, C, ra, sa, rb, sb );
  //matrix_product_banded(n, ra, rb,  sa,sb, A, B, C);
  // printAll matrix
  //

  printf("Matrix C\n");
  printMatrix(n, C);
  printf("\n");

  return 0;
}
