#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
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

    bubbleSort(A, sizeOfArray);

    cout << "\nSorted array is \n";
    printArray(A, sizeOfArray);
    return 0;
}