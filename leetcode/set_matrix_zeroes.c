//
// Created by hancheng on 18/11/2021.
//

#include <stdio.h>
#include <malloc.h>

void print_matrix(int** matrix, int matrixSize, const int* matrixColSize) {
    int i, j;
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < matrixColSize[i]; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int i, j;
    //int* row_zero = (int*)malloc(matrixColSize[0] * sizeof(int ));
    //int* col_zero = (int*)malloc(matrixSize * sizeof(int ));
    int row_zero[20];
    int col_zero[20];
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == 0) {
                row_zero[j] = 99;
                col_zero[i] = 99;
            }
        }
    }
    for (j = 0; j < matrixColSize[0]; j++) {
        if (row_zero[j] == 99) {
            for (i = 0; i < matrixSize; i++) {
                matrix[i][j] = 0;
            }
        }
    }
    for (i = 0; i < matrixSize; i++) {
        if (col_zero[i] == 99) {
            for (j = 0; j < matrixColSize[0]; j++) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    int row0[] = {8,7,7,4,1,6};
    int row1[] = {7,5,4,6,8,8};
    int row2[] = {0,9,4,3,0,5};
    int row3[] = {9,3,5,8,7,5};
    int row4[] = {0,1,0,8,9,7};
    int row5[] = {5,7,5,4,1,8};
    int row6[] = {2,0,6,7,7,4};
    int row7[] = {7,7,5,1,0,8};
    int* m[] = {row0, row1, row2, row3, row4, row5, row6, row7};
    int col_size[] = {6,6,6,6,6,6,6,6};
    print_matrix(m, sizeof(m)/sizeof(int*), col_size);
    setZeroes(m, sizeof(m)/sizeof(int*), col_size);
    printf("Done\n");
    print_matrix(m, sizeof(m)/sizeof(int*), col_size);
    return 0;
}