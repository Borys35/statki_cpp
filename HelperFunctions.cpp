#include "HelperFunctions.h"
#include <stdlib.h>

int HelperFunctions::random_between_two_numbers(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char HelperFunctions::get_char(int idx)
{
    switch (idx) {
    case 0:
        return '.';
    case 2:
        return '-';
    case 3:
        return '&';
    case 7:
        return '_';
    case 8:
        return 'X';
    default:
        return ';';
    }
}
