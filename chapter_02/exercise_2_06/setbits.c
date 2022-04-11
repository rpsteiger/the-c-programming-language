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

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{

    unsigned x = 0xd0, y = 0x06;
    int p, n;

    p = 3;
    n = 4;
    unsigned result = setbits(x, p, n, y);
    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(result));

    return 0;
}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned left_part = (x >> (p + 1 - n)) & (~0 << n);
    unsigned right_part = getbits(y, p, n);
    return left_part | right_part;
}