#include<time.h>
#include<stdio.h>
#include<stdlib.h>

void printMatrix(int r, int matrix[100][100]){
    int i, j;
    for(i = 0; i < r; i++) {
        for(j = 0; j < r; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

}

void swap(int *a, int *b) {
    int *c;
    c = a;
    a = b;
    b = c;
}

void transpose(int r, int target[100][100]){
    int i, j;
    for(i = 0; i < r; i ++) {
        for(j = 0; j < i; j++) {
            swap(&target[i][j], &target[j][i]);
        }
    }
}

int main(void){
    int i, j, r;
    int A[100][100], B[100][100];
    printf("Enter size r:");
    scanf("%d", &r);

    srand(time(NULL));

    // init matrix
    for(i = 0; i < r; i++) {
        for(j = 0; j < r; j++) {
            A[i][j] = rand() % 100;
        }
    }

    printMatrix(r, A);

    // transpose
    transpose(r, A);

    printf("\n");
    printMatrix(r, A);

    return 0;
}
