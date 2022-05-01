#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    /* char */
    /* notice: char is signed! */
    printf("CHAR_BITS: %d (should be 8)\n", CHAR_BIT);
    printf("CHAR_MIN: %d (should be -128)\n", CHAR_MIN);
    printf("CHAR_MAX: %d (should be 127)\n", CHAR_MAX);
    signed char max_char_value = 127;
    max_char_value += 1;
    signed char min_char_value = -128;
    min_char_value -= 1;
    printf("overflow char: 127 + 1: %d (should be -128)\n", max_char_value);
    printf("overflow 2 char: -128 - 1: %d (should be 127)\n", min_char_value);
    printf("\n\n");

    /* short */
    /* notice: short is signed by default! */
    printf("SHRT_MIN: %d (should be -32768)\n", SHRT_MIN);
    printf("SHRT_MAX: %d (should be 32767)\n", SHRT_MAX);
    short min_short_value = -32768;
    short max_short_value = 32767;
    min_short_value -= 1;
    max_short_value += 1;
    printf("overflow short: 32767 + 1: %d (should be -32768)\n", max_short_value);
    printf("overflow 2 short: -32768 - 1: %d (should be 32767)\n", min_short_value);
    printf("\n\n");

    /* int */
    /* notice: int is signed by default and 32 bit on my hp i5 machine */
    printf("INT_MIN: %d (should be -32768)\n", INT_MIN);
    printf("INT_MAX: %d (should be 32767)\n", INT_MAX);

    int min_int_value = -INT_MIN;
    int max_int_value = INT_MAX;
    min_int_value -= 1;
    max_int_value += 1;
    printf("overflow int: 2147483647 + 1: %d (should be -2147483648)\n", max_int_value);
    printf("overflow 2 int: -2147483648 - 1: %d (should be 2147483647)\n", min_int_value);
    printf("\n\n");

    /* long */
    printf("LONG_MIN: %ld (should be -9223372036854775808)\n", LONG_MIN);
    printf("LONG_MAX: %ld (should be 9223372036854775807)\n", LONG_MAX);

    return 0;
}