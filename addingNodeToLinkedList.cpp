#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() // Default constructor
    {
        head = NULL;
    }

    // Add new element at the end of the list
    void push_back(int newElement)
    {
        Node *newNode = new Node(); // creating a new node and filling it with data
        newNode->data = newElement;
        newNode->next = NULL;

        if (head == NULL) // If the list is empty
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;         // temp is pointing to the starting of the linked list
            while (temp->next != NULL) // traverse the whole linked list until we get to the last node(the one containing NULL in the linking part)
                temp = temp->next;
            temp->next = newNode; // We link the last node of the linked list to our newly created node
        }
    }

    // display the content of the list
    void PrintList()
    {
        Node *temp = head;
        if (temp != NULL)
        {
            cout << "The list contains: ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "The list is empty.\n";
        }
    }
};

// test the code
int main()
{
    LinkedList MyList;

    // Add three elements at the end of the list.
    MyList.push_back(10);
    MyList.push_back(20);
    MyList.push_back(30);
    MyList.PrintList();

    return 0;
}