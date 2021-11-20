//
// Created by hancheng on 20/11/2021.
//

#include <stdio.h>
#include <stdint-gcc.h>

int lengthOfLongestSubstring(char * s) {
    uint16_t ret = 0;
    uint16_t max = 0;
    // since ascii has 2^7 = 128 possibilities, we need 128/8 = 16 bytes
    uint8_t p[16] = {}; // init to zero! If we have [character] input, we mark bit [character] as 1
    uint8_t tmp;
    uint8_t g, b;
    char *i = s;
    while (*s != '\0') {
        g = *s >> 3; // group index = value / 8
        b = *s & 7; // bit index = value % 8
        tmp = 1 << b;
        if (tmp & p[g]) {
            // the new bit is already set in the p
            while (*s != *i) {
                p[*i >> 3] &= (uint8_t)(~(uint8_t)((1 << (*i & 7))));
                i++;
                ret--;
            }
            i++;
            ret--;
        } else {
            p[g] |= tmp;
        }
        s++;
        ret++;
        if (ret > max)
            max = ret;
    }
    return max;
}

int main() {
    char* input = "abcabcbb";
    printf("Input: %s\n", input);
    printf("Result: %d\n", lengthOfLongestSubstring(input));
    return 0;
}