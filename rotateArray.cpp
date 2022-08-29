#include <iostream>
using namespace std;

void rotate(int *arr, int k, int size)
{
    while (k > 0)
    {
        int lastElement = arr[size - 1];

        for (int i = size - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[0] = lastElement;

        k--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    rotate(arr, 3, 7);

    cout << "Rotated array by 3 places to the right is \n";

    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
