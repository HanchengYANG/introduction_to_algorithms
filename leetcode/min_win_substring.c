//
// Created by hancheng on 25/04/22.
//
#include <stdio.h>
#include <stdint.h>
#include <string.h>

char * minWindow(char * s, char * t) {
    int16_t feature[0x7F];
    size_t n = strlen(s), m = strlen(t);
    uint16_t counter = m;
    if (m > n)
        return "";
    memset(feature, 0, 0x7f * 2);
    int i;
    for (i = 0; i < m; i++) {
        feature[t[i]]++;
    }
    char *start = s, *end = s, *best_start = NULL;
    size_t best_len = 0;
    while (*end != '\0') {
        // remove *end from feature
        if (feature[*end]-- > 0)
            counter--;
        end++;
        // check if feature is all zero
        if (counter == 0) {
            while(counter == 0) {
                if (feature[*start]++ == 0)
                    counter++;
                start++;
            }
            if (best_start == NULL || end - start + 1 < best_len) {
                best_start = start - 1;
                best_len = end - start + 1;
            }
        }
    }
    if (best_start)
        best_start[best_len] = '\0';
    else
        best_start = "";
    return best_start;
}

int main() {
    char text[] = "ADOBECODEBANC";
    char s[] = "ABC";
    printf("%s\n", minWindow(text, s));
    return 0;
}