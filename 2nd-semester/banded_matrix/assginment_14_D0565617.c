/* Banded matrix multiplication. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Return the maximum value of x and y.
int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

// Return the minimum value of x and y.
int min(int x, int y)
{
    if (x < y)
        return x;
    else
        return y;
}

/* A: pointer to nxn banded matrix,
   B: pointer to nxn banded matrix,
   C: pointer to nxn banded matrix,
   r: the lower bandwidth of matrix A,
   s: the upper bandwidth of matrix B,
   Compute C=AB using banded matrix multiplication algorithm.
*/
void matrix_product_banded(int n, int r, int s,
                           int **A, int **B, int **C)
{
    int i, j, k; // Loop variable.
    // The three loops follow the indecies i, j, k
    // given in the formula of banded matrix multiplication.
    for (i = 0; i < n; i++)
        // max(0,i-ra-rb) <= j <= <=min(n-1,i+sa+sb)
        for (j = max(0, i - r); j <= min(n - 1, i + s); j++)
        {
            C[i][j - max(0, i - r)] = 0; // Initial c[i][j] to 0.
            // max(0, max(i-ra,j-sb)) <= k <= min(n-1,min(i+sa,j+rb))
            for (k = max(0, max(i - r, j - s)); k <= min(n - 1, min(i + s, j + r)); k++)
                // Each row of matrix A, B, and C are shift i-rx to the left,
                // where rx is the lower bandwidth A, B, or C, if i-rx>0.
                C[i][j - max(0, i - r)] += A[i][k - max(0, i - r)] * B[k][j - max(0, k - r)];
        }
}

/* 
   n: size of matrix
   r: lower bandwidth
   s: upper bandwidth
   A: nxn matrix,
   L: nxn lower triangular matrix,
   U: nxn upper triangular matrix.
   Compute A=LU.
*/
void LU_decompose(int n, int r, int s, float **A, float **L, float **U)
{
    int i, j, k;

    for (k = 0; k < n; k++)
    { // To compute submatrix A(k+1).
        for (j = k; j <= min(n - 1, k + s); j++)
            U[k][j - k] = A[k][j - max(0, k - r)]; // Compute elements of the k-th row of matrix U
        for (i = k; i <= min(n - 1, k + r); i++)
            L[i][k - max(0, i - r)] = A[i][k - max(0, i - r)] / A[k][k - max(0, k - r)]; // Compute elements of the k-th column of matrix L
        for (i = k + 1; i <= min(n - 1, k + r); i++)                                     // Compute elements of submatrix A(k+1):
            for (j = max(k + 1, i - r); j <= min(n - 1, min(i + s, k + s)); j++)
                A[i][j - max(0, i - r)] = A[i][j - max(0, i - r)] - L[i][k - max(0, i - r)] * U[k][j - k];
    }
}

/* A: nxn matrix,
   L: nxn lower triangular matrix,
   U: nxn upper triangular matrix.
   Compute A=LU.
*/
void Fixed_LU_decompose(int n, float A[100][100], float L[100][100], float U[100][100])
{
    int i, j, k;

    for (k = 0; k < n; k++)
    { // To compute submatrix A(k+1).
        for (j = k; j < n; j++)
            U[k][j] = A[k][j]; // Compute elements of the k-th row of matrix U
        for (i = k; i < n; i++)
            L[i][k] = A[i][k] / A[k][k]; // Compute elements of the k-th column of matrix L
        for (i = k + 1; i < n; i++)      // Compute elements of submatrix A(k+1):
            for (j = k + 1; j < n; j++)
                A[i][j] = A[i][j] - L[i][k] * U[k][j];
    }
}

int main(void)
{
    float A[100][100], L[100][100], U[100][100], A1[100][100];
    float **AA, **LL, **UU; // Pointers of two-dimensional arrays.
    int n;                  // Size of square matrices.
    int r, s;               // Lower bandwidth and upper bandwidth of matrix A.
    int i, j, k;            // Loop variables.
    int check;

    srand(0); // Seed of the random number generator.

    printf("Enter matrix size n: "); // Input the size of square matrices.
    scanf("%d", &n);
    // Input lower bandwidth and upper bandwidth of matrix A.
    printf("\nEnter the lower bandwidth and upper bandwidth of matrix A, r and s: ");
    scanf("%d %d", &r, &s);

    // Allocate dynamic memory for matrices LL, UU, and AA.
    LL = (float **)malloc(sizeof(float *) * n); // Pointers to rows of matrix L.
    for (i = 0; i < n; i++)
        LL[i] = (float *)malloc(sizeof(float) * (min(i, r) + 1)); // Rows of banded matrix A.
    UU = (float **)malloc(sizeof(float *) * n);                   // Pointers to rows of matrix U.
    for (i = 0; i < n; i++)
        UU[i] = (float *)malloc(sizeof(float) * (1 + min(n - 1 - i, s))); // Rows of banded matrix B.
    AA = (float **)malloc(sizeof(float *) * n);                           // Pointers to rows of matrix AA.
    for (i = 0; i < n; i++)
        AA[i] = (float *)malloc(sizeof(float) * (min(i, r) + 1 + min(n - 1 - i, s))); // Rows of banded matrix C.

    // Initial matrix A and A1 to 0.
    // In case of the off-band elements.
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            A1[i][j] = 0;
            A[i][j] = 0;
        }

    // Get values for the elements of matrix A.
    // Matrix element A[i][j], 0<A[i][j]<=1; A1[i][j] is the copy of A[i][j] for program verification.
    // 0<A[i][j]<=1.
    for (i = 0; i < n; i++)
        for (j = max(0, i - r); j <= min(n - 1, i + s); j++)
        {
            A[i][j] = A1[i][j] = (rand() % 10000 + 1) / 10000.0;

            AA[i][j - max(0, i - r)] = A[i][j];
        }

    printf("\nMatrix A:\n"); // Output matrix A.
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < max(0, i - r); j++)
            printf("         "); // Off-band elements of the lower band.
        for (j = max(0, i - r); j <= min(n - 1, i + s); j++)
            printf("%8.4f ", A[i][j]);
        printf("\n");
    }

    printf("\nMatrix AA:\n"); // Output matrix AA.
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < max(0, i - r); j++)
            printf("         "); // Off-band elements of the lower band.

        for (j = max(0, i - r); j <= min(n - 1, i + s); j++)

            printf("%8.4f ", AA[i][j - max(0, i - r)]);
        printf("\n");
    }

    printf("*********************************");

    // Compute banded matrix LU decompose.
    Fixed_LU_decompose(n, A, L, U);
    // Compute banded matrix LU decompose.
    LU_decompose(n, r, s, AA, LL, UU);

    printf("\nMatrix L:\n"); // Output matrix L.
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
            printf("%8.4f ", L[i][j]);
        printf("\n");
    }

    printf("\nMatrix LL:\n"); // Output matrix L.
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i - r; j++)
            printf("         "); // Off-band elements of the lower band.
        for (j = max(0, i - r); j <= i; j++)
            printf("%8.4f ", LL[i][j - max(0, i - r)]);
        printf("\n");
    }

    printf("*********************************");

    printf("\nMatrix U:\n"); // Ouput matrix U.
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
            printf("         "); // Do not print the lower triangular elements.
        for (j = i; j < n; j++)
            printf("%8.4f ", U[i][j]);
        printf("\n");
    }

    printf("\nMatrix UU:\n"); // Output matrix U.
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
            printf("         "); // Do not print the lower triangular elements.
        for (j = i; j <= min(n - 1, i + s); j++)
            printf("%8.4f ", UU[i][j - i]);
        printf("\n");
    }

    printf("*********************************");

    check = 1; // Intial flag to true.
    for (i = 0; i < n && check; i++)
        for (j = max(0, i - r); j <= min(n - 1, i + s) && check; j++)
        {
            A[i][j] = 0;
            // Compute A[i][j] for A<=LU.
            for (k = max(0, max(i - r, j - s)); k <= min(n - 1, min(i, j)); k++)
                A[i][j] += L[i][k] * U[k][j];
            check = check && (fabs(A[i][j] - A1[i][j]) < 0.0001); // Compare A[i][j] and A1[i][j], allow error 0.0001
        }

    if (check)
        printf("\nThe A LU-decomposition program is correct.\n"); // The program is correct.
    else
        printf("\nThe A LU-decomposition program is incorrect.\n"); // The program is incorrect.

    check = 1; // Intial flag to true.
    for (i = 0; i < n && check; i++)
        for (j = max(0, i - r); j <= min(n - 1, i + s) && check; j++)
        {
            AA[i][j] = 0;
            // Compute A[i][j] for A<=LU.
            for (k = max(0, max(i - r, j - s)); k <= min(n - 1, min(i, j)); k++)
                AA[i][j] += L[i][k] * U[k][j];
            check = check && (fabs(AA[i][j] - A1[i][j]) < 0.0001); // Compare A[i][j] and A1[i][j], allow error 0.0001
        }

    if (check)
        printf("\nThe AA LU-decomposition program is correct.\n"); // The program is correct.
    else
        printf("\nThe AA LU-decomposition program is incorrect.\n"); // The program is incorrect.

    // Deallocate memory space of matrices A, B, and C
    for (i = 0; i < n; i++)
    {
        free(AA[i]);
        free(LL[i]);
        free(UU[i]);
    }

    free(AA);
    free(LL);
    free(UU);

    return 0;
}
