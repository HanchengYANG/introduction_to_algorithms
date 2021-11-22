//
// Created by hancheng on 20/11/2021.
//

#include <stdio.h>
#include <stdint-gcc.h>
#include <string.h>
#include <malloc.h>

char * longestPalindrome(char * s) {
    /* Variable declaration */
    uint16_t s_len, m_len, i, *r, L, C, i_symm;
    char *manacher;
    /* Variable initialization */
    s_len = strlen(s);
    if (s_len == 0)
        return NULL;
    if (s_len == 1)
        return s;
    if (s_len == 2) {
        if (s[0] != s[1])
            s[1] = '\0';
        return s;
    }
    m_len = 2 * s_len + 1;
    manacher = (char*)malloc(m_len * sizeof(char));
    r = (uint16_t*)calloc(m_len, sizeof(uint16_t));
    /* Step 1, pre-process the string by insert "#" between every character */
    manacher[0] = '#';
    for (i = 0; i < s_len; i++) {
        manacher[(i << 1) + 1] = s[i];
        manacher[(i << 1) + 2] = '#';
    }
    /* Step 2, fill manacher result array */
    C = 0; // index of center of currently-right-est palindrome
    L = 0; // length of current palindrome
    for (i = 0; i < m_len; i++) {
        if (C + L > i) {
            // symmetric point: C - (i - C) = 2 * C - i
            i_symm = (C << 1) - i;
            // The symmetric palindrome is limited by start of string
            // So the r[i] maybe larger than r[i_symm], should continue
            if (i_symm == r[i_symm])
                r[i] = r[i_symm];
            // The size is too big, makes out of C + L, symmetric rule is not work
            // But at least it's symmetric until C + L
            if (i + r[i_symm] >= C + L)
                r[i] = C + L - i;
            // Perfect case
            if (i_symm > r[i_symm] && i + r[i_symm] < C + L) {
                r[i] = r[i_symm];
                continue;
            }
        }
        while(i - r[i] - 1 >= 0 && i + r[i] + 1 < m_len && manacher[i - r[i] - 1] == manacher[i + r[i] + 1]) {
            r[i]++;
        }
        C = i;
        L = r[i];
    }
    // Step 3, looking for biggest palindrome.
    s_len = 0; // reuse s_len as index of max value in r[] and r[0] = 0;
    for (i = 0; i < m_len; i++) {
        if (r[i] > r[s_len]) {
            s_len = i;
        }
    }
    s[(s_len + r[s_len] + 1)>>1] = '\0';
    s_len = (s_len - r[s_len] + 1)>>1;
    free(r);
    free(manacher);
    return &s[s_len];
}

int main() {
    char test[] = "babcbabcbaccbc";
    printf("%s\n", longestPalindrome(test));
    return 0;
}
