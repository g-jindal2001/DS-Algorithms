#include <iostream>
#include <vector>

using namespace std;

void generateBalancedParenthesis(int digit, int noOfOne, int noOfZero, string output_string)
{
    if (digit == 0)
    {
        cout << output_string << "\n";
        return;
    }

    string op1 = output_string;
    op1.push_back('1');
    generateBalancedParenthesis(digit - 1, noOfOne + 1, noOfZero, op1);

    if (noOfOne > noOfZero)
    {
        string op2 = output_string;
        op2.push_back('0');

        generateBalancedParenthesis(digit - 1, noOfOne, noOfZero + 1, op2);
    }
}

int main()
{
    int n = 5; // n-digit number
    string output = "";

    generateBalancedParenthesis(n, 0, 0, output);

    return 0;
}
