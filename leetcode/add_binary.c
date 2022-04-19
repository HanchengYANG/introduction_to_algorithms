//
// Created by hancheng on 19/04/22.
//

#include <stdint.h>
#include <malloc.h>
#include <string.h>

char * addBinary(char * a, char * b){
    int16_t a_len = strlen(a);
    int16_t b_len = strlen(b);
    char *w = (char*)malloc((a_len>b_len?a_len:b_len) + 2);
    w += (sizeof(w) - 1);
    *(w--) = '\0';
    uint8_t e = 0;
    while(a_len || b_len) {
        e += ((a_len ? *(a + (--a_len)) - 48 : 0) + (b_len ? *(b + (--b_len)) - 48 : 0));
        *(w--) = (e & 0x01) + 48;
        e>>=1;
    }
    if (e)
        *w = '1';
    else
        w++;
    return w;
}

int main() {
    printf("Result: %s\n", addBinary("11", "11"));
    return 0;
}