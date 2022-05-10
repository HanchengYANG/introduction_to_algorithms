//
// Created by hancheng on 10/05/22.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE

void gen_rand_array(int *array, unsigned int size, int min, int max) {
    srand(time(NULL));
    while(size) {
        size--;
        *(array + size) = min + (rand() % (max - min + 1));
    }
}

void merge(int *start, int *mid, int *end) {
    int *tmp = (int *)malloc(sizeof(int) * (end - mid));
    int *writer = end;
    int *ptr = tmp + (end - mid) - 1;
    memcpy(tmp, mid + 1, sizeof(int)*(end - mid));
    while(writer>=start && ptr>=tmp) {
        if (mid < start || *ptr > *mid) {
            *writer = *ptr;
            ptr--;
        } else {
            *writer = *mid;
            mid--;
        }
        writer--;
    }
    free(tmp);
}

void sort_merge(int *start, int *end) {
    int i;
    if (start < end) {
        sort_merge(start, start + (end - start) / 2);
        sort_merge(start + (end - start) / 2 + 1, end);
        merge(start, start + (end - start) / 2, end);
    }
}

int main() {
    int array[1000];
    sort_merge(array, &array[999]);
    return 0;
}
