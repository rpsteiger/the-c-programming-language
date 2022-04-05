#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXLINE 100

int htoi(char s[]);
int is_hex_char(char c);
int get_line(char line[], int lim);

int main(void)
{
    char hex[MAXLINE];

    printf("please enter a hex string: ");
    get_line(hex, MAXLINE);
    int converted_number;
    if ((converted_number = htoi(hex)) >= 0)
    {
        printf("%s in dec is: %d\n", hex, converted_number);
    }
    else
    {
        printf("%s contains invalid input\n");
    }
    return 0;
}

int htoi(char s[])
{
    /* convert all chars to lowercase */
    int i = 0, len = strlen(s);
    for (i = 0; i < len && s[i] != '\n' && s[i] != EOF; ++i)
    {
        s[i] = tolower(s[i]);
    }
    /* check if string starts with 0x */
    if (s[0] == '0' && s[1] == 'x')
    {
        i = 2;
    }
    else
    {
        i = 0;
    }
    /* convert the hex value to a decimal value */
    int power = len - 1, result = 0;
    if (s[0] == '0' && s[1] == 'x')
        power = power - 2;
    for (; i < len && s[i] != '\n' && s[i] != EOF; ++i)
    {
        if (!is_hex_char(s[i]))
            return -1;
        int current_char_value;
        if (isalpha(s[i]))
        {
            current_char_value = s[i] - 87;
        }
        else
        {
            current_char_value = s[i] - '0';
        }
        result = current_char_value * pow(16, power) + result;
        --power;
    }
    return result;
}

int is_hex_char(char c)
{
    c = tolower(c);
    if (isdigit(c))
    {
        return 1;
    }
    else if (isalpha(c) && c <= 'f')
    {
        return 1;
    }
    return 0;
}

int get_line(char line_buffer[], int limit)
{
    char c;
    int i = 0;

    while (i < limit - 1 && (c = getchar()) != EOF && c != '\n')
    {
        line_buffer[i++] = c;
    }

    line_buffer[i] = '\0';

    return i;
}