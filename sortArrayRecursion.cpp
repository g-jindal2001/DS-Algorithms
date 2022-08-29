#include <iostream>
#include <vector>

using namespace std;

void insertIterative(vector<int> &arr, int temp)
{
    bool flag = true;
    vector<int> result;
    for (int i = 0; i < arr.size(); i++)
    {
        if ((temp < arr[i]) && (flag = true))
        {
            result.push_back(temp);
            flag = false;
        }

        result.push_back(arr[i]);
    }

    for (int i = 0; i < result.size(); i++)
    {
        arr[i] = result[i];
    }
}

void insertRecursive(vector<int> &arr, int temp)
{
    if (arr.size() == 0 || arr[arr.size() - 1] <= temp)
    {
        arr.push_back(temp);
        return;
    }
    int x = arr[arr.size() - 1]; // take the last element
    arr.pop_back();
    insertRecursive(arr, temp);
    arr.push_back(x);
}

void sortRecursive(vector<int> &arr)
{
    if (arr.size() == 1) // arr already sorted
    {
        return;
    }

    int temp = arr[arr.size() - 1];

    arr.pop_back();

    sortRecursive(arr);

    insertRecursive(arr, temp);
}

int main()
{
    vector<int> arr = {7, 2, 5, 9, 8};
    sortRecursive(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}