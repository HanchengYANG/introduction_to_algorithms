//
// Created by hancheng on 15/04/22.
//
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int *w_ptr = NULL;
    int *r_ptr = nums;
    while(numsSize--) {
        if (!(numsSize >= 1 && *r_ptr == *(r_ptr + 1))){
            if (!w_ptr)
                w_ptr = nums;
            else
                *(++w_ptr) = *r_ptr;
        }
        r_ptr++;
    }
    return w_ptr - nums + 1;
}

int main() {
    int test[] = {1,1};
    printf("Result: %d\n", removeDuplicates(test, sizeof(test)/sizeof(int)));
    return 0;
}
