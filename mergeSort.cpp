#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(int array[], int left, int mid, int right)
{
    int arr1 = mid - left + 1; // create arr1[left..mid]
    int arr2 = right - mid;    // create arr2[mid+1..right]

    int *leftArray = new int[arr1],
        *rightArray = new int[arr2];

    for (int i = 0; i < arr1; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < arr2; j++)
        rightArray[j] = array[mid + 1 + j];

    int i1 = 0;
    int i2 = 0;
    int iFinal = left;

    while (i1 < arr1 && i2 < arr2)
    {
        if (leftArray[i1] <= rightArray[i2])
        {
            array[iFinal] = leftArray[i1];
            i1++;
        }
        else
        {
            array[iFinal] = rightArray[i2];
            i2++;
        }
        iFinal++;
    }

    while (i1 < arr1)
    {
        array[iFinal] = leftArray[i1];
        i1++;
        iFinal++;
    }

    while (i2 < arr2)
    {
        array[iFinal] = rightArray[i2];
        i2++;
        iFinal++;
    }
}

void mergeSort(int array[], int begin, int end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);

    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main()
{
    int A[10];
    int sizeOfArray;
    cout << "Enter the size of the array\n";
    cin >> sizeOfArray;
    cout << "Enter the elements of the array\n";

    for (int i = 0; i < sizeOfArray; i++)
        cin >> A[i];

    mergeSort(A, 0, sizeOfArray - 1);

    cout << "\nSorted array is \n";
    printArray(A, sizeOfArray);
    return 0;
}
