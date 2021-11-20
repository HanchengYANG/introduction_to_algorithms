//
// Created by hancheng on 19/11/2021.
//

#include <malloc.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b) {
    int i;
    int *am = *((int**)a);
    int *bm = *((int**)b);
    for (i = 1; i < 27; i++) {
        if (am[i] != bm[i]) {
            return bm[i] - am[i];
        }
    }
    return 0;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    int i;
    char *ptr;
    int **m = (int**)malloc(strsSize * sizeof(int*));
    for (i = 0; i < strsSize; i++) {
        ptr = strs[i];
        // allocate mem for each ptr, first number is index, then is alphabet statistics
        m[i] = (int*) calloc(27, sizeof(int));
        // Save order in first element of array
        m[i][0] = i;
        while (*ptr != '\0')
            m[i][*(ptr++) - 'a' + 1]++; //save statistics
    }
    // sort the "m"
    qsort(m, strsSize, sizeof(int*), cmp);
    // Initialize the return data
    *returnSize = 0;
    char *** ret = (char ***)malloc(strsSize * sizeof(char**));
    *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));
    for (i = 0; i < strsSize; i++) {
        if (i == 0 || memcmp(&m[i][1], &m[i - 1][1], 26 * sizeof(int)) != 0) {
            // New group
            ret[*returnSize] = (char**)malloc(strsSize * sizeof(char**));
            (*returnColumnSizes)[*returnSize] = 0;
            (*returnSize)++;
        }
        // Save str in group
        ret[*returnSize - 1][(*returnColumnSizes)[*returnSize - 1]] = strs[m[i][0]];
        (*returnColumnSizes)[*returnSize - 1]++;
    }
    return ret;
}

int main() {
    char* test[] = {
            "hhhhu",
            "tttti",
            "tttit",
            "hhhuh",
            "hhuhh",
            "tittt",
    };
    int retSize;
    int *retColSize;
    char ***res = groupAnagrams(test, 6, &retSize, &retColSize);
    int i, j;
    for (i = 0; i < retSize; i++) {
        printf("====Group %d====\n", i);
        for (j = 0; j < retColSize[i]; j++) {
            printf("%s\n", res[i][j]);
        }
    }
    return 0;
}
