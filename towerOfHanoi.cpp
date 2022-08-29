#include <iostream>

using namespace std;

void TowerOfHanoi(int s, int d, int h, int n)
{
    if (n == 1) // base condition is n == 1 instead of n == 0 since we want to move all the plates except for the last plate (which is the biggest one)
    {
        cout << "Moving plate " << n << " from " << s << " to " << d << "\n";
        return;
    }

    TowerOfHanoi(s, h, d, n - 1);

    // at this point all the plates (except for the last one) are pushed to helper tower and one plate (largest one) remaining in source and destination tower is empty

    cout << "Moving plate from " << s << " to " << d << "\n"; // moving last plate from source to destination

    // Now we move all the plates from helper to destination

    TowerOfHanoi(h, d, s, n - 1);
}

int main()
{
    int s = 1; // Tower 1 is source
    int d = 2; // Tower 2 is destination
    int h = 3;

    TowerOfHanoi(s, d, h, 3);
    return 0;
}