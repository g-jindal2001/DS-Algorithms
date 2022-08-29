#include <iostream>
using namespace std;

void palindrome(int n)
{
    int r, sum = 0, temp;
    temp = n;
    while (n > 0)
    {
        r = n % 10;
        sum = (sum * 10) + r;
        n = n / 10;
    }

    if (temp == sum)
    {
        cout << "Number is palindrome";
    }
    else
    {
        cout << "Number is not palindrome";
    }
}

int main()
{
    int number = 101;
    palindrome(number);
    return 0;
}
