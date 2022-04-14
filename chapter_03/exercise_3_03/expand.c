#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 36

void expand(char s1[], char s2[]);

int main(void)
{
    char test1[] = "a-z";
    char actual1[MAXLEN];
    expand(test1, actual1);
    printf("test 1: a-z -> \"%s\"\n", actual1);

    char test2[] = "a-b-c";
    expand(test2, actual1);
    printf("test 2: a-b-c -> \"%s\"\n", actual1);

    char test3[] = "a-c-h-v";
    expand(test3, actual1);
    printf("test 3: a-c-h-v -> \"%s\"\n", actual1);

    char test4[] = "a-c-b-v";
    expand(test4, actual1);
    printf("test 4: a-c-b-v -> \"%s\"\n", actual1);

    char test5[] = "0-9";
    expand(test5, actual1);
    printf("test 5: 0-9 -> \"%s\"\n", actual1);

    char test6[] = "1-5";
    expand(test6, actual1);
    printf("test 6: 1-5 -> \"%s\"\n", actual1);

    char test7[] = "a-zA-Z";
    expand(test7, actual1);
    printf("test 7: a-zA-Z -> \"%s\"\n", actual1);

    char test8[] = "a-z";
    expand(test8, actual1);
    printf("test 8: a-z -> \"%s\"\n", actual1);

    char test9[] = "-a-z";
    expand(test9, actual1);
    printf("test 9: -a-z -> \"%s\"\n", actual1);

    char test10[] = "a-z-";
    expand(test10, actual1);
    printf("test 10: a-z- -> \"%s\"\n", actual1);

    char test11[] = "-a-z-";
    expand(test11, actual1);
    printf("test 11: -a-z- -> \"%s\"\n", actual1);

    return 0;
}

void expand(char s1[], char s2[])
{
    int len = strlen(s1);
    int i = 0, j = 0;
    for (i = 0; i < len - 1; ++i)
    {
        while (isalnum(s1[i]) && s1[i + 1] == '-' && s1[i] < s1[i + 2])
        {
            int k = 0;
            for (k = 0; k <= (s1[i + 2]) - s1[i]; ++k)
            {
                if (s2[j - 1] != s1[i + k])
                {
                    s2[j++] = s1[i] + k;
                }
            }
            i += 2;
        }
    }
    s2[j] = '\0';
}
