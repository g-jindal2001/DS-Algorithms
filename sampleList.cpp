#include <iostream>
#include <list> // list in cpp is equal to doubly linked list

using namespace std;

int main()
{
    list<int> gqlist1;

    for (int i = 0; i < 10; ++i)
    {
        gqlist1.push_back(i * 2);
    }

    list<int>::iterator it;
    for (it = gqlist1.begin(); it != gqlist1.end(); ++it)
        cout << '\t' << *it;

    cout << '\n';

    return 0;
}