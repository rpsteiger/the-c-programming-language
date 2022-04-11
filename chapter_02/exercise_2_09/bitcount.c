#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c\n"
#define BYTE_TO_BINARY(byte)     \
    (byte & 128 ? '1' : '0'),    \
        (byte & 64 ? '1' : '0'), \
        (byte & 32 ? '1' : '0'), \
        (byte & 16 ? '1' : '0'), \
        (byte & 8 ? '1' : '0'),  \
        (byte & 4 ? '1' : '0'),  \
        (byte & 2 ? '1' : '0'),  \
        (byte & 1 ? '1' : '0')

int bitcount(unsigned x);

int main(void)
{
    unsigned a = 0xff;
    printf("x = 0xff, x &= (x-1)\n");
    a &= (a - 1);
    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(a));

    unsigned x = 0b10101010;
    int bitcount_result = bitcount(x);
    printf("bitcount(0b10101010) returns: %d", bitcount_result);

    return 0;
}

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x - 1))
        ++b;
    return b;
}