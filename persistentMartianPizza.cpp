#include <iostream>
#include <vector>
using namespace std;

vector<int> outputResult(vector<int> input_array, int order_size, int window_size)
{
    vector<int> output;
    for (int i = 0; i < order_size - window_size + 1; i++)
    {
        int found = 0;
        for (int j = i; j < i + window_size; j++)
        {
            if (input_array[j] < 0)
            {
                output.push_back(input_array[j]);
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            output.push_back(0);
        }
    }

    return output;
}

int main()
{
    int no_of_orders, size_of_window;
    cout << "Enter the order size\n";
    cin >> no_of_orders;
    cout << "Enter the window size\n";
    cin >> size_of_window;

    vector<int> orders, result;
    int temp;

    cout << "Enter the elements of the array\n";
    for (int i = 0; i < no_of_orders; i++)
    {
        cin >> temp;
        orders.push_back(temp);
    }

    result = outputResult(orders, no_of_orders, size_of_window);

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';

    return 0;
}