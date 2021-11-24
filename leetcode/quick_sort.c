//
// Created by hancheng on 24/11/2021.
//
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define LIST_SIZE 100
#define ELEMENT_MIN 0
#define ELEMENT_MAX 100

int partition(int *arr, int low, int high) {
    int pivot = arr[low];
    while(low < high) {
        while (low < high && arr[high] >= pivot)
            --high;
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot)
            ++low;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

void quick_sort(int *arr, int low, int high) {
    if (low >= high)
        return;
    int pivot_index = partition(arr, low, high);
    quick_sort(arr, low, pivot_index - 1);
    quick_sort(arr, pivot_index + 1, high);
}

int main() {
    int *list = (int*)malloc(LIST_SIZE * sizeof(int));
    u_int16_t i;
    // Generate list of random number
    srand(time(NULL));
    for (i = 0; i < LIST_SIZE; i++)
        list[i] = ELEMENT_MIN + (rand() % (ELEMENT_MAX - ELEMENT_MIN));
    quick_sort(list, 0, LIST_SIZE - 1);
    for (i = 0; i < LIST_SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}