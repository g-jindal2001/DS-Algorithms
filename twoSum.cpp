#include <iostream>
using namespace std;

int indices[2];
void printArray(int A[], int size);

void twoSum(int A[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            try
            {
                if (A[i] + A[j] == target)
                {
                    indices[0] = i;
                    indices[1] = j;
                }
            }
            catch (...)
            {
            }
        }
    }
    cout << "\n";
    printArray(indices, 2);
}

void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main()
{
    int arr[] = {3, 3};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int target = 6;

    cout << "Given array is \n";
    printArray(arr, arr_size);

    twoSum(arr, arr_size, target);

    return 0;
}