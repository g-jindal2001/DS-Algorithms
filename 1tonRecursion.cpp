#include <iostream>
#include <vector>

using namespace std;

int sum = 0;

void printTill1(int n)
{
    if (n == 0)
    {
        return;
    }

    cout << n << "\n";

    printTill1(n - 1);
}

void printTillN(int n)
{
    if (n == 0)
    {
        return;
    }

    printTillN(n - 1);

    cout << n << "\n";
}

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    int number = fibonacci(n - 2) + fibonacci(n - 1);
    return number;
}

int fibonacciSum(int n)
{
    if (n == 0)
    {
        sum += 0;
        return 0;
    }

    if (n == 1)
    {
        sum += 1;
        return 1;
    }

    int number = fibonacciSum(n - 2) + fibonacciSum(n - 1);
    return sum;
}

int main()
{
    int n = 10;
    printTill1(n);
    cout << "\n";
    printTillN(n);
    // int number = fibonacciSum(8);
    // cout << number;

    return 0;
}