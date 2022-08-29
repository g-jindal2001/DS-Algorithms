#include <iostream>
#include <vector>

using namespace std;

void josephusProblem(vector<int> people, int k, int index)
{
    if (people.size() == 1)
    {
        cout << people[0];
        return;
    }

    index = (index + k - 1) % people.size();
    people.erase(people.begin() + index);

    josephusProblem(people, k, index);
}

int main()
{
    vector<int> people;
    int n = 40; // no of people

    for (int i = 1; i <= n; i++)
    {
        people.push_back(i);
    }

    int k = 7;

    josephusProblem(people, k--, 0);
}