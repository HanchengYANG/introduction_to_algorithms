//
// Created by hancheng on 20/04/22.
//
#include <stdio.h>
#include <string.h>
#include <malloc.h>

static inline void calculate_rm(char *s, int *l, int *r) {
    int score = 0;
    *l = 0;
    *r = 0;
    while (*s != '\0') {
        if (*s == '(')
            score++;
        if (*s == ')')
            score--;
        if (score < 0) {
            score = 0;
            (*r)++;
        }
        s++;
    }
    *l = score;
}

void move_one_step(char *s, int l, int r, int cur_index, char ***res, int *returnSize) {
    // remove right parentheses first
    int nl, nr;
    char *tmp;
    int i, j;
    int ignore = 0;
    char match = r ? ')' : '(';
    int s_len = strlen(s);
    for(i = cur_index; i < s_len; i++) {
        if (s[i] == match) {
            if (!ignore) {
                tmp = (char *) malloc(s_len);
                memcpy(tmp, s, i);
                memcpy(tmp + i, s + i + 1, s_len - i);
                calculate_rm(tmp, &nl, &nr);
                if (nl + nr == 0) {
                    for (j = 0; j < *returnSize; j++) {
                        if (strcmp(tmp, (*res)[j]) == 0)
                            break;
                    }
                    if (j == *returnSize) {
                        if (*res == NULL) {
                            *res = (char **) malloc(sizeof(char *));
                            *returnSize = 1;
                        } else {
                            *res = (char **) realloc(*res, (*returnSize + 1) * sizeof(char *));
                            (*returnSize)++;
                        }
                        (*res)[(*returnSize) - 1] = tmp;
                    }
                } else if (nl + nr < l + r) {
                    move_one_step(tmp, nl, nr, i + 1 < s_len ? i : 0, res, returnSize);
                }
                ignore = 1;
            }
        } else {
            ignore = 0;
        }
    }
}

char ** removeInvalidParentheses(char * s, int* returnSize) {
    int l, r;
    char ** res = NULL;
    calculate_rm(s, &l, &r);
    if (l + r == 0) {
        res = (char **) malloc(sizeof(char*));
        res[0] = s;
        *returnSize = 1;
    } else {
        *returnSize = 0;
        move_one_step(s, l, r, 0, &res, returnSize);
    }
    return res;
}


int main() {
    char test[] = ")d))";
    int ret_size = 0;
    char **res = removeInvalidParentheses(test, &ret_size);
    int i;
    for (i = 0; i < ret_size; i++) {
        printf("[%d] %s\n", i + 1, res[i]);
    }
    return 0;
}