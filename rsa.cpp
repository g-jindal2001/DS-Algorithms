#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

bool isPrime(int a)
{
    int count = 0;
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            count++;
        }
    }

    if (count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int a, b, n;
    double num;
    cout << "Please enter the two prime numbers\n";
    cin >> a;
    cin >> b;

    if (!(isPrime(a) && isPrime(b)))
    {
        cout << "Sorry the numbers are not prime";
        return 0;
    }

    cout << "Please enter the message to be encrypted\n";
    cin >> num;
    n = a * b;
    double e = 2;
    double phi = (a - 1) * (b - 1); // totient function

    while (e < phi)
    { // e should be co prime to the totient function
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    int k = 2;
    double d = (1 + (k * phi)) / e; // private key
    double c = pow(num, e);
    c = fmod(c, n);
    cout << "\nEncrypted Message\n"
         << c;
    double m = pow(c, d);
    m = fmod(m, n);
    cout << "\nOrginal Message\n"
         << m;

    return 0;
}