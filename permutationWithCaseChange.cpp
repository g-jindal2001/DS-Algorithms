#include <iostream>

using namespace std;

void permutationWithSpaces(string input_string, string output_string)
{
    if (input_string.length() == 0)
    {
        cout << output_string << "\n";
        return;
    }

    string op1 = output_string;
    string op2 = output_string;

    op1.push_back(input_string[0]);

    op2.push_back(input_string[0] - 32);

    input_string = input_string.substr(1);

    permutationWithSpaces(input_string, op1);
    permutationWithSpaces(input_string, op2);
}

int main()
{
    string input_string = "abc";
    string output_string = "";

    permutationWithSpaces(input_string, output_string);
    return 0;
}