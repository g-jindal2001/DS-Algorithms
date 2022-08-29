#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <omp.h>
#define MAX 10000000
#define threads 4
int a[MAX], b[MAX], c[MAX];
void serial(int op)
{
    for (int i = 0; i < MAX; i++)
    {
        if (op == 1)
            c[i] = a[i] + b[i];
        if (op == 2)
            c[i] = a[i] - b[i];
        if (op == 3)
            c[i] = a[i] * b[i];
    }
}
void parallel(int op)
{
#pragma omp parallel for default(none), shared(a, b, c, op)
    for (int i = 0; i < MAX; i++)
    {
        // printf("Thread: %d i: %d\n", omp_get_thread_num(), i);
        if (op == 1)
            c[i] = a[i] + b[i];
        if (op == 2)
            c[i] = a[i] - b[i];
        if (op == 3)
            c[i] = a[i] * b[i];
    }
}
int main()
{
    // omp_set_num_threads(threads);
    for (int i = 0; i < MAX; i++)
    {
        a[i] = rand() % 20;
        b[i] = rand() % 20;
    }
    double start, end;
    start = omp_get_wtime();
    serial(3);
    end = omp_get_wtime();
    printf("Serial Time:   %f\n", (end - start));

    start = omp_get_wtime();
    parallel(3);
    end = omp_get_wtime();
    printf("Parallel Time: %f\n", (end - start));

    return 0;
}