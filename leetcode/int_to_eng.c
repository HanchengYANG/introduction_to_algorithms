//
// Created by hancheng on 19/04/22.
//
#include <stdio.h>
#include <stdint.h>
#include <string.h>

char num1[] = "One";
char num2[] = "Two";
char num3[] = "Three";
char num4[] = "Four";
char num5[] = "Five";
char num6[] = "Six";
char num7[] = "Seven";
char num8[] = "Eight";
char num9[] = "Nine";
char num10[] = "Ten";
char num11[] = "Eleven";
char num12[] = "Twelve";
char num13[] = "Thirteen";
char num14[] = "Fourteen";
char num15[] = "Fifteen";
char num16[] = "Sixteen";
char num17[] = "Seventeen";
char num18[] = "Eighteen";
char num19[] = "Nineteen";
char num20[] = "Twenty";
char num30[] = "Thirty";
char num40[] = "Forty";
char num50[] = "Fifty";
char num60[] = "Sixty";
char num70[] = "Seventy";
char num80[] = "Eighty";
char num90[] = "Ninety";
char num100[] = "Hundred";

char *nums[] = {
        NULL, num1, num2,num3,num4,num5,num6,num7,num8,num9,
        num10, num11,num12,num13,num14,num15,num16,num17,num18,num19
};

char *tens[] = {
        NULL, NULL, num20, num30, num40, num50, num60, num70, num80, num90, num100
};

char *ten_cubes[] = {
        "", " Thousand", " Million", " Billion"
};

static inline char * basic(int num) {
    if (num < 20) {
        return nums[num];
    } else if (num <= 100){
        return tens[num / 10];
    } else {
        return NULL;
    }
}

static inline char * ks(int degree) {
    return ten_cubes[degree];
}

char * lessThenThousandToWords(int num) {
    static char res[200];
    uint8_t hundred = num / 100;
    uint8_t t;
    res[0] = '\0';
    if (hundred) {
        strcat(res, basic(hundred));
        strcat(res, " ");
        strcat(res, basic(100));
        num %= 100;
        if (num)
            strcat(res, " ");
    }
    if (num > 20) {
        strcat(res, basic(num / 10 * 10));
        num %= 10;
        if (num) {
            strcat(res, " ");
            strcat(res, basic(num));
        }
    } else if (num) {
        strcat(res, basic(num));
    }
    return res;
}

char * numberToWords(int num) {
    static char res[200];
    res[0] = '\0';
    int i, f = 1000 * 1000 * 1000;
    if (num == 0)
        return "Zero";
    for (i = 3; i >= 0; i--) {
        if (num / f) {
            strcat(res, lessThenThousandToWords(num / f));
            strcat(res, ks(i));
            if (num % f)
                strcat(res, " ");
        }
        if (!num % f) {
            break;
        } else {
            num %= f;
            f /= 1000;
        }
    }
    return res;
}

int main() {
    printf("Result: %s\n", numberToWords(1000010001));
}