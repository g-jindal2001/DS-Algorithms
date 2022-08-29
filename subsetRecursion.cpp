#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void subset(string input_string, string output_string) // subset and subsequence same code
{
    if (input_string.length() == 0)
    {
        cout << output_string << "\n";
        return;
    }

    string op1 = output_string;
    string op2 = output_string;

    op2.push_back(input_string[0]);
    input_string = input_string.substr(1);

    subset(input_string, op1);
    subset(input_string, op2);
}

void uniqueSubset(string input_string, string output_string, unordered_set<string> &uset) // & in uset is very inportant
{
    if (input_string.length() == 0)
    {
        uset.insert(output_string);
        return;
    }

    string op1 = output_string;
    string op2 = output_string;

    op2.push_back(input_string[0]);
    input_string = input_string.substr(1);

    uniqueSubset(input_string, op1, uset);
    uniqueSubset(input_string, op2, uset);
}

void subsetNumber(vector<int> input_vector, vector<int> output_vector)
{
    if (input_vector.size() == 0)
    {
        for (int i = 0; i < output_vector.size(); i++)
        {
            cout << output_vector[i] << " ";
        }
        cout << "\n";

        return;
    }

    vector<int> op1 = output_vector;
    vector<int> op2 = output_vector;

    op2.push_back(input_vector[0]);
    input_vector.erase(input_vector.begin());

    subsetNumber(input_vector, op1);
    subsetNumber(input_vector, op2);
}

int main()
{
    string input_string = "abc";
    string output_string = "";

    vector<int> input_vector = {3, 3, 6, 8};
    vector<int> output_vector;

    // unordered_set<string> uset;

    // uniqueSubset(input_string, output_string, uset);

    // for (auto i = uset.begin(); i != uset.end(); ++i)
    // {
    //     cout << (*i) << endl;
    // }

    subsetNumber(input_vector, output_vector);

    // subset(input_string, output_string);

    return 0;
}