#include <iostream>
using namespace std;

int euclideanGcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return euclideanGcd(b % a, a);
}

int lcm(int a, int b)
{
    return (a * b) / euclideanGcd(a, b);
}

int main()
{
    int a = 30;
    int b = 20;
    int gcd = euclideanGcd(a, b);
    int lcma = lcm(a, b);
    cout << gcd << "\n";
    cout << lcma;
    return 0;
}