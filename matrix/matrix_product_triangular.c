#include<time.h>
#include<stdio.h>
#include<stdlib.h>

void printMatrix(int r, int matrix[100][100]) {
    int i, j;
    for(i = 0; i < r; i++){
        for(j = 0; j< r; j++){
            printf("%4d ", matrix[i][j]);

        }
        printf("\n");
    }
}

int min(int a, int b){
    if (a >= b){
        return b;
    }
    return a;
}

void product(int r, int A[100][100],int B[100][100], int C[100][100]) {
    int i, j, k;

    for(i = 0; i < r; i ++) {
        for(j=0; j < r; j++) {
            C[i][j] = 0;
            for(k = 0; k <= min(i, j); k ++) {
                C[i][j] +=  B[i][k] * A[k][j] ;
            }
        }
    }
}


int main(void) {
    int i, j, r;
    int upper[100][100], lower[100][100], C[100][100];

    srand(time(NULL));

    printf("Enter size r:");
    scanf("%d", &r);

    // init
    for(i = 0; i < r; i++){
        for(j=0; j <= i ; j++) {
             lower[i][j]= rand()%10 + 1;
        }
    }
    for(i = 0; i < r; i++){
        for(j=i; j < r; j++) {
            upper[i][j] = rand()%10 + 1;
        }
    }

    printf("Lower:\n");
    printMatrix(r, lower);
    printf("Upper:\n");
    printMatrix(r, upper);
    product(r, upper, lower, C);
    printf("Ans:\n");
    printMatrix(r, C);


    return 0;
}
