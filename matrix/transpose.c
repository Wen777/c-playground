#include<time.h>
#include<stdlib.h>
#include<stdio.h>

void printMatrix(int m, int n, float matrix[100][100]) {
    int i, j;
    for(i = 0; i <m ; i++) {
        for(j = 0; j <n; j++) {
            printf("%4.2f ", matrix[i][j]);

        }
        printf("\n");
    }
}

void transpose(int m, int n, float target[100][100], float std[100][100]) {
    int i, j;
    for(i = 0; i < m; i++) {
        for (j=0; j<n ; j++){
            std[j][i] = target[i][j];
        }
    }
}

int main(void) {

    int m,n,i,j;
    float A[100][100], B[100][100];

    printf("Enter m and n:");
    scanf("%d %d",  &m, &n);

    srand(time(NULL));

    for(i=0; i< m; i++) {
        for(j= 0; j<n;j++) {
            A[i][j] = rand() %100;
        }
    }

    printMatrix(m, n, A);
    transpose(m, n, A, B);
    printf("\n");
    printMatrix(n, m, B);
    return 0;
}
