#include <stdio.h>
#include <string.h>

unsigned int binary_to_uint(const char *b) {
    unsigned int num = 0;
    int len = strlen(b);
    for (int i = 0; i < len; i++) {
        if (b[i] == '1') {
            num = (num << 1) | 1;
        } else if (b[i] == '0') {
            num <<= 1;
        } else {
            return 0;
        }
    }
    return num;
}

