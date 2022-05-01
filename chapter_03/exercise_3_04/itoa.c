#include <stdio.h>
#include <limits.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
    char result[100];
    itoa(INT_MIN, result);
    printf("itoa(INT_MIN, result) should be %d, result:\"%s\"", INT_MIN, result);

    return 0;
}

void itoa(int n, char s[])
{
    int i, sign;

    i = 0;
    do
    {
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);
    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}