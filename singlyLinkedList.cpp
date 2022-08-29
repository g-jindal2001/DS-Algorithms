#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void printLinkedList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

void addNodeAtEnd(int newValue, Node *headpointer)
{
    Node *newNode = new Node();
    newNode->data = newValue;
    newNode->next = NULL;

    if (headpointer == NULL)
    {
        headpointer = newNode;
    }
    else
    {
        Node *temp = headpointer;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void addNodeAtPos(int newValue, int pos, Node *headpointer)
{
    Node *newNode = new Node();
    newNode->data = newValue;
    newNode->next = NULL;

    if (pos < 1)
    {
        cout << "\nposition should be >= 1.";
    }
    else if (pos == 1)
    {
        // cout << "called";
        newNode->next = headpointer;
        headpointer = newNode;
    }
    else
    {
        Node *temp = headpointer;
        for (int i = 1; i < pos - 1; i++) // Traversing till the given position
        {
            if (temp != NULL)
            {
                temp = temp->next;
            }
        }

        if (temp != NULL)
        {
            newNode->next = temp->next; // New Node should point to the old Node at the same position. (in order to connect with the next node in sequence)
            temp->next = newNode;       // the old node's next pointer connection to the newNode
        }
        else
        {
            cout << "\nThe previous node is null.";
        }
    }
}

void deleteNodeAtPos(int pos, Node *headpointer)
{
    if (pos < 1)
    {
        cout << "\nposition should be >= 1.";
    }
    else if (pos == 1) // head pointer should be deleted
    {
        headpointer = headpointer->next;
    }
    else
    {
        Node *temp = headpointer;
        for (int i = 1; i < pos - 1; i++) // Traversing till the given position
        {
            if (temp != NULL)
            {
                temp = temp->next;
            }
        }

        if (temp != NULL && temp->next != NULL)
        {
            temp->next = temp->next->next;
        }
    }
}

int searchElement(int pos, Node *headpointer)
{
    if (pos < 1)
    {
        cout << "\nposition should be >= 1.";
        return -1;
    }
    else if (pos == 1) // head pointer's value should be returned
    {
        return headpointer->data;
    }
    else
    {
        Node *temp = headpointer;
        for (int i = 1; i < pos; i++) // Traversing till the given position
        {
            if (temp != NULL)
            {
                temp = temp->next;
            }
        }

        return temp->data;
    }
}

int main()
{
    Node *head = NULL;
    Node *first = NULL;
    Node *second = NULL;

    head = new Node();
    first = new Node();
    second = new Node();

    head->data = 1;
    head->next = first;

    first->data = 2;
    first->next = second;

    second->data = 3;
    second->next = NULL;

    addNodeAtEnd(4, head);

    addNodeAtPos(8, 5, head);

    deleteNodeAtPos(2, head);

    printLinkedList(head);

    int returnedValue = searchElement(1, head); // search the element at 4th index

    cout << "\n"
         << returnedValue;

    return 0;
}