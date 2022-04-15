//
// Created by hancheng on 15/04/2022.
//
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int myAtoi(char * s) {
    char *ptr =s;
    int sign;
    int result = 0;
    uint8_t digit;
    // Step 1: search for "-"/number
    while (*ptr == ' ')
        ptr++;
    if (*ptr == '-') {
        sign = -1;
        ptr++;
    } else if (*ptr == '+') {
        sign = 1;
        ptr++;
    } else {
        if (*ptr >= '0' && *ptr <= '9') {
            sign = 1;
        } else {
            return 0;
        }
    }
    while (*ptr != '\0' && (*ptr >= '0' && *ptr <= '9')) {
        digit = *ptr - '0';
        if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        result = result * 10 + digit;
        ptr++;
    }
    return result * sign;
}

int main() {
    char test[] = "+1";
    int res = myAtoi(test);
    printf("Res: %d\n", res);
    return 0;
}