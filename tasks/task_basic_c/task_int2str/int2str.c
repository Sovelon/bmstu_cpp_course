#include <assert.h>
#include "int2str.h"
#include <stdio.h>
#include <stdlib.h>

char* int2str(int num) {
    int isNg = 0;
    if (num < 0) {
        isNg = 1;
        if (num == -2147483648) {
            return ("-2147483648");
        }
        num = -num;
    }

    int x = num;
    int length = 0;
    do {
        length++;
        x /= 10;
    } while (x > 0);

    if (isNg) {
        length++;
    }

    char *str = (char *)malloc(length + 1);
    if (!str) {
        return 0;
    }

    int q = 0;
    do {
        str[q++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    if (isNg) {
        str[q++] = '-';
    }

    str[q] = '\0';

    for (int j = 0; j < q / 2; j++) {
        char x = str[j];
        str[j] = str[q - j - 1];
        str[q - j - 1] = x;
    }

    return str;
}