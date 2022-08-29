#include <iostream>

using namespace std;

int partition(int *, int, int);
void random_qs(int *, int, int);
int random_partition(int *, int, int);

int main()
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\n**** Randomized Quick Sort ****" << endl;
    int p = 1, r = n;
    random_qs(arr, p, r);
    cout << "\nSorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

void random_qs(int *a, int p, int r)
{
    int q;
    if (p < r)
    {
        q = random_partition(a, p, r);
        random_qs(a, p, q - 1);
        random_qs(a, q + 1, r);
    }
}

int random_partition(int *a, int p, int r)
{
    int i = p + rand() % (r - p + 1);
    int temp;
    temp = a[r];
    a[r] = a[i];
    a[i] = temp;
    return partition(a, p, r);
}
int partition(int *a, int p, int r)

{
    int temp, temp1;
    int x = a[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (a[j] <= x)
        {
            i = i + 1;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp1 = a[i + 1];
    a[i + 1] = a[r];
    a[r] = temp1;
    return i + 1;
}
