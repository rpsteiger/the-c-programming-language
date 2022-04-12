#include <stdio.h>
#include <time.h>

#define VECTOR_SIZE 1000000
#define ITERATIONS 10000000

void init_vector(int v[], int n);
void print_vector(int v[], int n);

void test_binsearch(int x, int v[], int n);

int binsearch_kr(int x, int v[], int n);
int binsearch(int x, int v[], int n);

int main(void)
{
    // int even_numbers[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    // int len = 10;
    // int result = binsearch_kr(13, even_numbers, len);
    // printf("binsearch(13, even_numbers, 10) should return -1\n");
    // printf("output: %d\n", result);

    // result = binsearch_kr(16, even_numbers, len);
    // printf("binsearch(16, even_numbers, 10) should return 8\n");
    // printf("output: %d\n", result);

    int v[VECTOR_SIZE];
    init_vector(v, VECTOR_SIZE);
    // print_vector(v, VECTOR_SIZE);

    int x = -1;
    test_binsearch(x, v, VECTOR_SIZE);

    return 0;
}

void init_vector(int v[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        v[i] = i;
    }
}

void print_vector(int v[], int n)
{
    printf("[");
    for (int i = 0; i < n; ++i)
    {
        (i == n - 1) ? printf("%d]\n", i) : printf("%d,", i);
    }
}

void test_binsearch(int x, int v[], int n)
{
    double total_time = 0;

    for (int j = 0; j < 10; ++j)
    {
        clock_t start = clock();
        for (int i = 0; i < n; ++i)
        {
            binsearch_kr(x, v, n);
        }
        clock_t stop = clock();
        double time_elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
        printf("execution %d: %.4f seconds\n", j + 1, time_elapsed);
        total_time += time_elapsed;
    }
    printf("average execution time is %.4f\n", total_time / 10);
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

int binsearch(int x, int v[], int n)
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
        else
        {
            low = mid + 1;
        }
    }
    return (x == v[mid]) ? v[mid] : -1;
}

/*
notes: removing an if from the loop makes a bigger difference than I anticipated.
on my machine (i5-10310U) the revised version runs 17% faster on average.
*/