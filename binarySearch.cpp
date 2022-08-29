#include <iostream>
using namespace std;

int binarySearch(int a[], int sizeOfArray, int element)
{
    int low = 0;
    int high = sizeOfArray - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (element == a[mid])
        {
            return element;
        }
        else if (element < a[mid])
        {
            low = mid + 1;
        }
        else if (element > a[mid])
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int A[] = {7, 2, 1, 6, 8, 5, 3, 4};

    int a = binarySearch(A, 8, 9);

    if (a == -1)
    {
        cout << "Element not found in the array";
    }
    else
    {
        cout << "Element found in the array";
    }

    return 0;
}