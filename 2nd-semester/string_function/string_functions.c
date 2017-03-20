#ifndef string_functions
#define string_functions
#include <string.h>
#include "string_functions.h"

size_t strlen_ite(const char *str) {
    size_t length;
    for (length=0; str[length] != '\0'; length ++ );
    return length;
}

size_t strlen_rec(const char *str) {
    if (*str == '\0') {
        return 0;
    } else {
        return strlen_rec(str + 1) + 1;
    }
}

int strcmp_ite(const char *str1, const char *str2){
    int result = 0;
    int i = 0;

    while (!result && str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] > str2[i]) {
            result = 1;
        } else if (str1[i] < str2[i]) {
            result = -1;
        }
        i++;
    } 

    if (! result && str1[i] != '\0') {
        result = 1;
    } else if (!result && str2[i] != '\0') {
        result = -1;
    }

    return result;
}

int strcmp_rec(const char *str1, const char *str2) {
    if (*str1 == * str2) {
        if (*str1 == '\0') {
            return 0;
        } else {
            return strcmp_rec(str1 + 1, str2 + 1);
        }   
    } else if   (*str1 > *str2) {
        return 1;
    } else  {
        //if (*str1 < *str2)
        return -1;
    }
}

char *strcpy_ite(char *str1, const char *str2) {
    int i;

    for (i = 0; str2[i] != '\0'; i++) {
        str1[i] = str2[i];
    }

    str1[i] = '\0';
    return str1;
}


#endif
