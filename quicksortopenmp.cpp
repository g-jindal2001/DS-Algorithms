#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <algorithm>
#define MAX 100000
int a[MAX];
int k = 0;
int partition(int arr[], int low_index, int high_index)
{
    int i, j, temp, key;
    key = arr[low_index];
    i = low_index + 1;
    j = high_index;
    while (1)
    {
        while (i < high_index && key >= arr[i])
            i++;
        while (key < arr[j])
            j--;
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else
        {
            temp = arr[low_index];
            arr[low_index] = arr[j];
            arr[j] = temp;
            return (j);
        }
    }
}
void quicksortParallel(int arr[], int low_index, int high_index)
{
    int j;
    if (low_index < high_index)
    {
        j = partition(arr, low_index, high_index);
#pragma omp parallel sections
        {
#pragma omp section
            {
                k = k + 1;
                quicksortParallel(arr, low_index, j - 1);
            }
#pragma omp section
            {
                k = k + 1;
                quicksortParallel(arr, j + 1, high_index);
            }
        }
    }
}

void quicksortSerial(int arr[], int low_index, int high_index)
{
    int j;
    if (low_index < high_index)
    {
        j = partition(arr, low_index, high_index);
        {
            {
                k = k + 1;
                quicksortSerial(arr, low_index, j - 1);
            }
            {
                k = k + 1;
                quicksortSerial(arr, j + 1, high_index);
            }
        }
    }
}

int main()
{
    for (int i = 0; i < MAX; i++)
    {
        a[i] = rand() % 20;
    }

    int temp[MAX];

    for (int i = 0; i < MAX; i++)
    {
        temp[i] = a[i];
    }

    double start, start2, end2, end;

    start2 = omp_get_wtime();
    quicksortSerial(temp, 0, MAX - 1);
    end2 = omp_get_wtime();
    printf("Serial Time:   %f\n", (end2 - start2));

    start = omp_get_wtime();
    quicksortParallel(a, 0, MAX - 1);
    end = omp_get_wtime();
    printf("Parallel Time: %f\n", (end - start));
}
