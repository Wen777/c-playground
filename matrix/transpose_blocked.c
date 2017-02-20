#include<time.h>
#include<stdlib.h>
#include<stdio.h>

void printMatrix(int m, int n, int matrix[100][100]){
    int i, j;

    for (i=0; i < m; i++) {
        for(j=0; j<n; j++) {
            printf("%3d ", matrix[i][j]);
        }

        printf("\n");
    }
}

void transpose_blocked(int block, int m, int n, int matrix01[100][100],int matrix02[100][100]) {
    int i, j, x,y;
    for(i = 0; i < m / block; i++) {
        for(j = 0; j< n/ block; j++) {
            for(x = 0; x < block; x++){
                for(y= 0; y < block; y ++) {
                    matrix02[i * block + y][ j* block + x] = matrix01[ i * block + x][ j*block + y ];
                }
            }
        }
    }

}


int main(void){
    int i, j, m, n, d;
    int A[100][100], B[100][100];

    printf("block");

    scanf("%d", &d);

    printf("Enter m and n:");
    scanf("%d %d", &m, &n);

    srand(time(NULL));

    // init matrix
    for(i= 0; i < m; i++) {
        for(j=0; j<n; j++){
            A[i][j] = rand() % 100;
        }
    }

    printMatrix(m, n, A);


    transpose_blocked(d, m, n, A, B);
    printf("\n");

    printMatrix(n, m, B);

    return 0;
}
