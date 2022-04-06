#include <stdio.h>

int any(char s1[], char s2[]);

int main(void)
{
    char s1[] = "the quick brown dog jumps over the lazy dog";
    char s2[] = "z34";
    char s3[] = "@#!";

    printf("Calling any() with \"%s\". This should return 37\n", s2);
    printf("output: %d", any(s1, s2));
    printf("\n");
    printf("Calling any() with \"%s\". This should return -1\n", s3);
    printf("output: %d", any(s1, s3));

    return 0;
}

int any(char s1[], char s2[])
{
    char c1, c2;
    int i = 0, j;
    while ((c1 = s1[i]) != '\0')
    {
        j = 0;
        while ((c2 = s2[j]) != '\0' && c2 != c1)
        {
            ++j;
            if (c1 == c2)
                break;
        }
        if (c1 == c2)
            break;
        ++i;
    }
    if (c1 == c2 && c1 != '\0')
    {
        return i;
    }
    else
    {
        return -1;
    }
}