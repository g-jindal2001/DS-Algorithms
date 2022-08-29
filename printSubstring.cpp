#include <iostream>

using namespace std;

void printSubstring(string input)
{
    for (int i = 0; i < input.size(); i++)
    {
        string subString;
        for (int j = i; j < input.size(); j++)
        {
            subString = subString + input[j];
            cout << subString << "\n";
        }
    }
}

int main()
{
    string input_string = "abc";
    printSubstring(input_string);
    return 0;
}