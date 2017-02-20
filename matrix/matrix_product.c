#include<time.h>
#include<stdio.h>
#include<stdlib.h>

void product(int m, int n, int p, int target01[100][100], int target02[100][100], int std[100][100] ){
    int i, j, k;
    for(i = 0; i < m; i++){
        for(j=0; j < p; j++){
            //init
            std[i][j] = 0;
            for(k =0; k< n; k++){
                std[i][j] += target01[i][k] * target02[k][j];
            }
        }
    }
}

void printMatrix(int row, int column, int matrix[100][100]) {
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < column; j ++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}


int main(void) {
    int i, j, m, n, p;
    int C[100][100], A[100][100], B[100][100];

    srand(time(NULL));

    printf("Enter m, n, p");
    scanf("%d %d %d", &m, &n, &p);

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < p; j++) {
            B[i][j] = rand() % 10;
        }
    }

    // init
    printMatrix(m, n, A);
    printf("\n");
    printMatrix(n, p, B);
    // product
    product(m, n, p, A, B, C);
    // print two
    printf("\n");
    printMatrix(m, p, C);
}
