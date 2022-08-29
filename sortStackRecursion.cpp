#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void insertRecur(stack<int> &s, int temp)
{
    if (s.empty())
    {
        s.push(temp);
        return;
    }
    else if (s.top() <= temp)
    {
        s.push(temp);
        return;
    }

    int val = s.top();
    s.pop();
    insertRecur(s, temp);
    s.push(val);
    return;
}

void sortRecur(stack<int> &s)
{
    if (s.size() == 1)
        return;

    int temp = s.top();
    s.pop();
    sortRecur(s);

    insertRecur(s, temp);
    return;
}

void insertRecursive(stack<int> &s, int temp)
{
    if (s.empty() || s.top() <= temp) // base condition
    {
        s.push(temp);
        return;
    }

    int last = s.top();
    s.pop();
    insertRecursive(s, temp);
    s.push(last);
    return;
}

void sortRecursive(stack<int> &s)
{
    if (s.size() == 1) // stack already sorted
    {
        return;
    }

    int temp = s.top();
    s.pop();

    sortRecursive(s);

    insertRecursive(s, temp);
    return;
}

int main()
{
    // stack<int> s;

    // s.push(7);
    // s.push(2);
    // s.push(5);
    // s.push(9);
    // s.push(8);

    // sortRecur(s);

    // for (int i = 0; i < s.size(); i++)
    // {
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    string demo = "abcd";

    cout << demo.substr(1);
}
