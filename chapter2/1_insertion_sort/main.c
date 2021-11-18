#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE

void gen_rand_array(int *array, unsigned int size, int min, int max) {
    srand(time(NULL));
    while(size) {
        size--;
        *(array + size) = min + (rand() % (max - min + 1));
    }
}

void insert_sort(int *array, int size) {
    int i, j;
    int key;
    for (i = 1; i < size; i++) {
        key = array[i]; // This is the new one, array before it has already been sorted
        j = i - 1; // This is the index of the largest in sorted array
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int main() {
    int array[1000];
    gen_rand_array(array, 1000, -10000, 10000);
    insert_sort(array, 1000);
    return 0;
}
