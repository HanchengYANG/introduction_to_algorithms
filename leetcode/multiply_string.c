//
// Created by hancheng on 16/04/22.
//

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>

char * multiply(char * num1, char * num2) {
    /* n digits integer multiplied by m digits integer cannot longer than n + m digits
     * because: n digits int < 10^n - 1, same for m digits int
     * 10^n x 10^m = 10^(n + m), which is the smallest n + m + 1 digits integer, while
     * 10^n has n+1 digits and 10^m has m+1 digits, n digits int x m digits int < 10^(n+m) - 1
     * that's n + m digits.
     */
    uint8_t n1_len = strlen(num1), n2_len = strlen(num2);
    if ((*num1 == '0' && n1_len == 1) || (*num2 == '0' && n2_len == 1))
        return "0";
    uint16_t res_len = n1_len + n2_len;
    char *result = (char *)malloc(res_len * sizeof(char) + 1);
    result[res_len] = '\0';
    char *w = result + res_len - 1;
    char *n1_ptr;
    char *n2_ptr;
    n2_ptr = num2 + n2_len - 1;
    uint8_t *digit_pd = (uint8_t *)malloc(n1_len * n2_len * sizeof(uint8_t));
    uint32_t i, j;
    i = 0;
    uint16_t column, accumulate;
    while (n2_ptr >= num2) {
        n1_ptr = num1 + n1_len - 1;
        j = 0;
        while (n1_ptr >= num1) {
            digit_pd[i * n1_len + j++] = (*n2_ptr - '0') * (*n1_ptr - '0');
            n1_ptr--;
        }
        n2_ptr--;
        i++;
    }
    for (i = 0; i < n2_len; i++) {
        for (j = 0; j < n1_len; j++) {
            printf("[%d,%d]=%d\t", i, j, digit_pd[i * n1_len + j]);
        }
        printf("\n");
    }
    accumulate = 0;
    for (i = 0; i < n1_len + n2_len - 1; i++) {
        column = 0;
        for (j = 0; j <= i; j++) {
            if (j < n2_len && (i - j) < n1_len) {
                printf("[%d, %d] = %d\t", j, (i - j), digit_pd[j * n1_len + (i - j)]);
                column += digit_pd[j * n1_len + (i - j)];
            }
        }
        *(w--) = (column + accumulate) % 10 + '0';
        accumulate = (column + accumulate) / 10;
        printf("\n");
    }
    if (accumulate)
        *w = accumulate + '0';
    else
        w++;
    return w;
}

int main() {
    char n1[] = "99999";
    char n2[] = "99999";
    printf("%s x %s = %s\n", n1, n2, multiply(n1, n2));
    return 0;
}