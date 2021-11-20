//
// Created by hancheng on 18/11/2021.
//

#include <stdio.h>
#include <malloc.h>

void print_matrix(int** matrix, int matrixSize, const int* matrixColSize) {
    int i, j;
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < matrixColSize[i]; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int i, j, tmp = matrix[0][0], row_size = matrixColSize[0];
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < row_size; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                if (j == 0)
                    tmp = 0; // Represents if the first column has 0
                else
                    matrix[0][j] = 0;
            }
        }
    }

    for (i = 1; i < matrixSize; i++) {
        for (j = 1; j < row_size; j++) {
            // j cannot be 0, so tmp is not used
            if(matrix[0][j] == 0 || matrix[i][0] == 0)
                matrix[i][j] = 0;
        }
    }

    // check first row
    if (matrix[0][0] == 0) {
        for (j = 1; j < row_size; j++)
            matrix[0][j] = 0;
    }

    // check first column
    if (tmp == 0) {
        for (i = 1; i < matrixSize; i++)
            matrix[i][0] = 0;
    }
    if (tmp == 0)
        matrix[0][0] = 0;
}

int main() {
    int row0[] = {1,2,3,4};
    int row1[] = {5,0,7,8};
    int row2[] = {0,10,11,12};
    int row3[] = {13,14,15,0};
    int* m[] = {row0, row1, row2, row3};
    int col_size[] = {4,4,4,4};
    print_matrix(m, sizeof(m)/sizeof(int*), col_size);
    setZeroes(m, sizeof(m)/sizeof(int*), col_size);
    printf("Done\n");
    print_matrix(m, sizeof(m)/sizeof(int*), col_size);
    return 0;
}