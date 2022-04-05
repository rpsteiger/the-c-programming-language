#include <stdio.h>

main()
{
    int i, c;
    int lim = 100;
    char s[100];

    /*for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    {
        s[i] = c;
    }*/
    c = getchar();
    for (i = 0; i < lim - 1;)
    {
        if (c == '\n')
            break;
        if (c == EOF)
            break;
        s[i] = c;

        ++i;
        c = getchar();
    }
    printf("%s", s);

    return 0;
}