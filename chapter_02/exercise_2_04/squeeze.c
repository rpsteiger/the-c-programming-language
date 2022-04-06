#include <stdio.h>
#include <string.h>

void squeeze(char input[], char too_replace[]);
int any(char c, char match_any[]);

int main(void)
{
    char input[] = "blah blah blubbi blub blub -.-";
    char replace_chars[] = "au ";

    printf("calling squeeze with input '%s'; attempting to replace the chars '%s'.\n", input, replace_chars);
    squeeze(input, replace_chars);
    printf("output: %s", input, replace_chars);

    return 0;
}

void squeeze(char input[], char too_replace[])
{
    int i, j;

    for (i = j = 0; input[i] != '\0'; i++)
    {
        if (!any(input[i], too_replace))
        {
            input[j++] = input[i];
        }
    }
    input[j] = '\0';
}

int any(char c, char match_any[])
{
    char c2;
    int i = 0;
    while ((c2 = match_any[i]) != '\0' && c2 != c)
        ++i;
    int len = strlen(match_any);
    return (i < len || c2 == c);
}