#include "str2int.h"
#include <stdio.h>
#include <assert.h>

int str2int(const char *str) {
    int result = 0;
    int znak = 1;
    int nummax = 2147483647;
    int nummin = (-2147483648);
    
    while (*str == ' ') {
        str++;
    }

    if (*str == '\0') {
        assert(0); 
    }

    if (*str == '-') {
        znak = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }
    
    if (*str == '\0') {
        assert(0); 
    }

    while ((*str >= '0' && *str <= '9') && *str != '\0') {
        if (znak == 1 && result > (nummax - (*str - '0')) / 10) {
            assert(0);
        }
        if (znak == -1 && -result < (nummin + (*str - '0')) / 10) {
            assert(0);
        }
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * znak;
}
