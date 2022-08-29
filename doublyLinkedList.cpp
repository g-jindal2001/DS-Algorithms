#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
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
    newNode->prev = NULL;

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
        newNode->prev = temp;
    }
}

void addNodeAtPos(int newValue, int pos, Node *headpointer)
{
    Node *newNode = new Node();
    newNode->data = newValue;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (pos < 1)
    {
        cout << "\nposition should be >= 1.";
    }
    else if (pos == 1)
    {
        newNode->next = headpointer;
        headpointer->prev = newNode;
        headpointer = newNode; // Imp
    }
    else
    {
        Node *temp = headpointer;
        for (int i = 1; i < pos - 1; i++)
        {
            if (temp != NULL)
            {
                temp = temp->next;
            }
        }

        if (temp != NULL)
        {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            if (newNode->next != NULL) // imp line without with trying to add a number at the end of doubly linked list will fail
                newNode->next->prev = newNode;
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
        headpointer->prev = NULL;
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

        temp->next = temp->next->next;
        temp->next->next->prev = temp->next; // Confusing (Revise)
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
    head->prev = NULL;

    first->data = 2;
    first->next = second;
    first->prev = head;

    second->data = 3;
    second->next = NULL;
    second->prev = first;

    addNodeAtEnd(4, head);

    addNodeAtPos(8, 2, head);

    deleteNodeAtPos(2, head);

    printLinkedList(head);

    // int returnedValue = searchElement(1, head); // search the element at 4th index

    // cout << "\n"
    //      << returnedValue;

    return 0;
}