#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string removeKdigits(string number, int noOfDigits)
{
    int originalNum = stoi(number);
    int n = number.size();
    stack<char> mystack;

    for (char c : number)
    {
        while (!mystack.empty() && noOfDigits > 0 && mystack.top() > c) // if a previous maxima is present we simply remove the top element of stack and decrement k
        {
            cout << "Top element of stack being popped" << mystack.top() << "\n";
            mystack.pop();
            noOfDigits -= 1;
        }

        if (!mystack.empty() || c != '0') // if there is no previous maxima
        {
            mystack.push(c);
            cout << "Top element of stack" << mystack.top() << "\n";
        }
    }

    // special case if noOfDigits is still not zero we simply remove the largest values from top of stack
    while (!mystack.empty() && noOfDigits--)
        mystack.pop();

    if (mystack.empty())
        return 0;

    // Now retrieve the number from stack into a string
    // (reusing num)
    while (!mystack.empty())
    {
        number[n - 1] = mystack.top();
        mystack.pop();
        n -= 1;
    }

    return number.substr(n);

    // int finalNum = stoi(number.substr(n));

    // return originalNum - finalNum;
}

int main()
{
    string str = "765028321";
    int k = 5;
    cout << removeKdigits(str, k);
    return 0;
}