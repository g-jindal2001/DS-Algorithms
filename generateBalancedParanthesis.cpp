#include <iostream>
#include <vector>

using namespace std;

void generateBalancedParenthesis(int open, int closed, string output_string)
{
    if (open == 0 && closed == 0)
    {
        cout << output_string << "\n";
        return;
    }

    if (open != 0)
    {
        string op = output_string;
        op.push_back('(');

        generateBalancedParenthesis(open - 1, closed, op);
    }

    if (open < closed) // condition for add closed bracket
    {
        string op2 = output_string;
        op2.push_back(')');

        generateBalancedParenthesis(open, closed - 1, op2);
    }
}

int main()
{
    int n = 3; // no of pairs of parenthesis
    string output = "";

    generateBalancedParenthesis(n, n, output);

    return 0;
}
