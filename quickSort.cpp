#include <bits/stdc++.h>
using namespace std;

int Partition(int *A, int start, int end)
{
    int pivotElement = A[end];
    int pIndex = start; //set partition index as start intially
    for (int i = start; i < end; i++)
    {
        if (A[i] <= pivotElement)
        {
            swap(A[i], A[pIndex]); //swap if element is lesser than pivot
            pIndex++;
        }
    }
    swap(A[pIndex], A[end]); //Swap pivot with the last element after loop is done
    return pIndex;
}

int* QuickSort(int *A, int start, int end)
{
    if (start < end)
    {
        int partitionIndex = Partition(A, start, end);
        QuickSort(A, start, partitionIndex - 1); //Sorting left side of Partition index
        QuickSort(A, partitionIndex + 1, end);   //Sorting right side of Partition index
    }

    return A;
}

int main()
{
    int A[] = {7, 2, 1, 6, 8, 5, 3, 4};
    int* ptr = QuickSort(A, 0, 7);
    for (int i = 0; i < 8; i++)
    {
        cout << ptr[i] << " ";
    }
    return 0;
}