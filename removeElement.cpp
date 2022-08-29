#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (val == nums[i])
        {
            count++;
            nums.erase(nums.begin() + i);
        }
    }

    return count;
}

int main()
{
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int count = removeElement(nums, val);
    cout << count;
    return 0;
}