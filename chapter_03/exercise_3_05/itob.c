#include <stdio.h>
#include <string.h>

#define STRING_SIZE 100

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
    /* calling itob on a base that is not supported should
    return the char array unmodified */
    char s[STRING_SIZE];
    int number1 = 30061995;

    itob(number1, s, 3);
    printf("test1 should return empty string: \"%s\"\n", s);

    /* test2: converting a dec to a binary value */
    char s2[STRING_SIZE];
    int number2 = 75;
    itob(number2, s2, 2);
    printf("75 binary should return \"100'1011\": \"%s\"\n", s2);

    /* test3: converting a dec to a hex value */
    char s3[STRING_SIZE];
    int number3 = 258;
    itob(number3, s3, 16);
    printf("258 hex should return \"0x102\": \"%s\"\n", s3);

    /* test4: converting a dec to a octal value */
    char s4[STRING_SIZE];
    int number4 = 1231;
    itob(number4, s4, 8);
    printf("258 hex should return \"2317\": \"%s\"\n", s4);

    return 0;
}

void itob(int n, char s[], int b)
{
    if (!(b == 2 || b == 8 | b == 16))
    {
        return;
    }

    int r = 0, i = 0, n2 = n;

    do
    {
        r = n2 % b;
        if (b == 16 && r > 10)
        {
            s[i++] = 'a' + r - 10;
        }
        else
        {
            s[i++] = '0' + r;
        }

    } while ((n2 = n2 / b) > 0);
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