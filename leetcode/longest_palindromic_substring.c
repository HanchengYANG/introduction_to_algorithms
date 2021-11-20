//
// Created by hancheng on 20/11/2021.
//

#include <stdio.h>
#include <stdint-gcc.h>
#include <string.h>
#include <malloc.h>

char * longestPalindrome(char * s) {
    uint16_t s_size = strlen(s);
#define M_SIZE_BYTE (s_size * s_size / 8 + 1)
    // Matrix [s_size] x [s_size] bits, we need it initialized to zeros
    uint8_t *m = (uint8_t*)calloc(M_SIZE_BYTE, sizeof(uint8_t));
    uint16_t i, l, i_max = 0, j_max = 0, ret_size = 0; // string length max 1000
#define M_SET(i, j) (m[((i) * s_size + (j)) >> 3] |= (1 << (((i) * s_size + (j)) & 0x07)))
#define M_GET(i, j) (m[((i) * s_size + (j)) >> 3] & (1 << (((i) * s_size + (j)) & 0x07)))
    // l is the distance to the diagonal
    for (l = 0; l < s_size; l++) {
        for (i = 0; i < s_size; i++) {
            if (i + l > s_size - 1)
                break;
            else {
                if (l == 0) {
                    // It's diagonal line
                    M_SET(i, i);
                } else if (l == 1) {
                    // It's string len = 2, if there a equal then it's palindrome
                    if (s[i] == s[i + 1])
                        M_SET(i, i + 1);
                } else {
                    /* For size larger than 2,
                     * 1: if starting character equals ending character,
                     * 2: if inner string is palindrome
                     * Then it's palindrome */
                    if (s[i] == s[i + l] && M_GET(i + 1, i + l - 1))
                        M_SET(i, i + l);
                }
            }
        }
    }
    for (i = 0; i < s_size; i++) {
        for (l = i; l < s_size; l++) {
            if (M_GET(i, l) && ((l - i) > ret_size)) {
                i_max = i;
                j_max = l;
                ret_size = l - i;
            }
        }
    }
    free(m);
    s[j_max + 1] = '\0';
    return &s[i_max];
}

int main() {
    char test[] = "acaabcdefghijk";
    printf("%s: ", test);
    printf("%s\n", longestPalindrome(test));
    return 0;
}
