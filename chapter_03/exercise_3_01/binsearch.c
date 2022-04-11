#include <stdio.h>

int binsearch_kr(int x, int v[], int n);

int main(void)
{
    int even_numbers[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int len = 10;
    int result = binsearch_kr(13, even_numbers, len);
    printf("binsearch(13, even_numbers, 10) should return -1\n");
    printf("output: %d\n", result);

    result = binsearch_kr(16, even_numbers, len);
    printf("binsearch(16, even_numbers, 10) should return 8\n");
    printf("output: %d\n", result);

    return 0;
}

int binsearch_kr(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}