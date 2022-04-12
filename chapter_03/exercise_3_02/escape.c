#include <stdio.h>

#define MAXLEN 100

int get_line(char line[], unsigned int limit);
void escape(char source[], char target[]);
void unescape(char source[], char target[]);

int main(void)
{
    char source[MAXLEN];
    char target[MAXLEN];

    get_line(source, MAXLEN);
    printf("original: \"%s\"\n", source);
    escape(source, target);
    printf("escaped: \"%s\"\n", target);
    unescape(target, source);
    printf("unescaped: \"%s\"\n", source);

    return 0;
}

int get_line(char line[], unsigned int limit)
{
    int i, c;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}
void escape(char source[], char target[])
{
    char c;
    int i = 0, j = 0;
    while ((c = source[i]) != '\0')
    {
        switch (c)
        {
        case '\n':
            target[j++] = '\\';
            target[j++] = 'n';
            break;
        case '\t':
            target[j++] = '\\';
            target[j++] = 't';
            break;
        default:
            target[j++] = c;
            break;
        }
        ++i;
    }
}
void unescape(char source[], char target[])
{
    char c, c2;
    int i = 0, j = 0;
    while ((c = source[i]) != '\0')
    {
        switch (c)
        {
        case '\\':
            c2 = source[++i];
            if (c2 == 'n')
            {
                target[j++] = '\n';
            }
            else if (c2 == 't')
            {
                target[j++] = '\t';
            }
            break;
        default:
            target[j++] = c;
            break;
        }
        ++i;
    }
}