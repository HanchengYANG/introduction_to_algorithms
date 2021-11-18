#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int nums[], int numsSize, int* returnSize, int** returnColumnSizes) {
    int i;
    int *start;
    int *end;
    *returnSize = 0;
    int res_buffer_size = 64;
    *returnColumnSizes = (int*)malloc(res_buffer_size * sizeof(int));
    int** ret = (int**)malloc(res_buffer_size * sizeof(int*));
    // Special case
    if (numsSize < 3)
        return ret;
    if (numsSize == 3 && (nums[0] + nums[1] + nums[2] == 0)) {
        (*returnSize)++;
        //*returnColumnSizes = (int*) malloc(sizeof(int));
        (*returnColumnSizes)[0] = 3;
        //ret = (int**)malloc(sizeof(int*));
        ret[0] = (int*)malloc(3 * sizeof(int));
        ret[0][0] = nums[0];
        ret[0][1] = nums[1];
        ret[0][2] = nums[2];
        return ret;
    }
    // sort
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    i = 0;
    for (i = 0; i < numsSize - 2 && nums[i] <= 0; i++) {
        // target for 2 sum is -nums[i]
        start = nums + i + 1;
        end = nums + numsSize - 1;
        while (start < end) {
            if (-nums[i] > (*end) * 2)
                break;
            if (-nums[i] < (*start) * 2)
                break;
            if (*start + *end == -nums[i]) {
                if (++(*returnSize) > res_buffer_size) {
                    res_buffer_size *= 2;
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, res_buffer_size * sizeof(int));
                    ret = (int**) realloc(ret, res_buffer_size * sizeof(int*));
                }
                (*returnColumnSizes)[*returnSize - 1] = 3;
                ret[*returnSize - 1] = (int*)malloc(3 * sizeof(int));
                ret[*returnSize - 1][0] = nums[i];
                ret[*returnSize - 1][1] = *start;
                ret[*returnSize - 1][2] = *end;
                while (start < end && *start == *(start + 1) && start++);
                start++;
                while (start < end && *end == *(end - 1) && end--);
                end--;
            } else if (*start + *end < -nums[i]) {
                while (start < end && *start == *(start + 1) && start++);
                start++;
            } else {
                while (start < end && *end == *(end - 1) && end--);
                end--;
            }
        }
        while ((i < numsSize - 2) && (nums[i] == nums[i + 1]))
            i++;
    }
    return ret;
}

int main() {
    int array[] = {
            -1,0,1,2,-1,-4
    };
    int resSize = 0;
    int *retColSize;
    int **result = threeSum(array, sizeof(array)/sizeof(int), &resSize, &retColSize);
    int i;
    for (i = 0; i < resSize; i++) {
        printf("[ %d, %d, %d ]\n", result[i][0], result[i][1], result[i][2]);
    }
    printf("Result count %d\n", resSize);
    printf("Done");
    return 0;
}
