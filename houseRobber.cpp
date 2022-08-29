#include <vector>
#include <iostream>
using std::vector;
using namespace std;

int rob(vector<int> &nums)
{
    int sumodd, sumeven = 0;

    if (nums.size() == 2)
    {
        if (nums[0] > nums[1])
        {
            return nums[0];
        }
        else
        {
            return nums[1];
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (i % 2 == 0)
        {
            sumeven += nums[i];
        }
        else
        {
            sumodd += nums[i];
        }
    }

    if (sumodd > sumeven)
    {
        return sumodd;
    }
    else
    {
        return sumeven;
    }
}

int main()
{
    cout << "Hello World";
    vector<int> arr = {1, 3, 1};
    int result;

    result = rob(arr);

    cout << result;

    return 0;
}