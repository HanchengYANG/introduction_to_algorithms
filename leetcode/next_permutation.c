//
// Created by hancheng on 16/04/22.
//

#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

void nextPermutation(int* nums, int numsSize){
    int *end = nums + (numsSize - 1);
    int *from_this_ptr_descend_order = end;
    int *step_point;
    int *step_point_replace;
    int tmp, i;
    for (i = 0; i < numsSize; i++)
        printf("%d ", nums[i]);
    printf("\n");
    while (from_this_ptr_descend_order > nums) {
        if (*(from_this_ptr_descend_order - 1) < *from_this_ptr_descend_order)
            break;
        from_this_ptr_descend_order--;
    }
    printf("From [%ld] it descending...\n", from_this_ptr_descend_order - nums);
    if (from_this_ptr_descend_order != nums) {
        step_point = from_this_ptr_descend_order - 1;
        step_point_replace = step_point;
        while (step_point_replace < end && *(step_point_replace + 1) > *step_point) {
            step_point_replace++;
        }
        tmp = *step_point;
        *step_point = *step_point_replace;
        *step_point_replace = tmp;
    }
    qsort(from_this_ptr_descend_order, end - from_this_ptr_descend_order + 1, sizeof(int), cmpfunc);
    for (i = 0; i < numsSize; i++)
        printf("%d ", nums[i]);
    printf("\n");
}

int main() {
    int test[] = {1,5,1};
    int i = 0;
    while (i < 100) {
        nextPermutation(test, sizeof(test)/sizeof(int));
        i++;
    }
    return 0;
}