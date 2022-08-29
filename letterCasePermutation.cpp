#include <iostream>
#include <cctype>

using namespace std;

void permutationWithSpaces(string input_string, string output_string)
{
    if (input_string.length() == 0)
    {
        cout << output_string << "\n";
        return;
    }

    if (isdigit(input_string[0]))
    {
        string op = output_string;
        op.push_back((input_string[0]));

        input_string = input_string.substr(1);
        permutationWithSpaces(input_string, op);
    }
    else
    {
        string op1 = output_string;
        string op2 = output_string;

        op1.push_back(tolower(input_string[0]));

        op2.push_back(toupper(input_string[0]));

        input_string = input_string.substr(1);

        permutationWithSpaces(input_string, op1);
        permutationWithSpaces(input_string, op2);
    }
}

int main()
{
    string input_string = "a1B2";
    string output_string = "";

    permutationWithSpaces(input_string, output_string);
    return 0;
}