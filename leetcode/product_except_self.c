//
// Created by hancheng on 19/04/22.
//
#include <malloc.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int *res = (int *)malloc(numsSize * sizeof(int));
    int i, tmp;
    res[0] = 1;
    for (i = 1; i < numsSize; i++) {
        res[i] = res[i - 1] * nums[i - 1];
    }
    tmp = 1;
    for (i = numsSize - 2; i >= 0; i--) {
        tmp *= nums[i + 1];
        res[i] *= tmp;
    }
    *returnSize = numsSize;
    return res;
}