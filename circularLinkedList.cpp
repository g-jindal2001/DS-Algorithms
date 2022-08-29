#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

void printLinkedList(Node *headpointer)
{
    Node *temp = headpointer;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
        if(temp == headpointer) {
            break;
        }
    }
}

void addNodeAtPos(int newValue, int pos, Node *headpointer) 
{
    Node *newNode = new Node();
    newNode->data = newValue;
    newNode->next = NULL;

    Node* temp = headpointer;
    int NoOfElements = 0;

    if(temp != NULL) {
        NoOfElements++;
        temp = temp->next;
    }
    while(temp != headpointer) {
        NoOfElements++;
        temp = temp->next;
    }

    if(pos < 1 || pos > (NoOfElements+1)) 
    {
        cout<<"\nInavalid position.";
    } 
    else if (pos == 1) 
    {
        if(headpointer == NULL) 
        {
            headpointer = newNode;
            headpointer->next = headpointer;
        } 
        else 
        {
            while(temp->next != headpointer) //lopp till the end of the circular linked list (till the last element of the linked list)
            {
                temp = temp->next;
            }
            newNode->next = headpointer; //connecting newNode with headpointer
            headpointer = newNode; //assigning newNode as the new headpointer
            temp->next = headpointer;// connecting last element of linked list to newNode (which is the now the head pointer)
        }
    }
    else //same as singly Linked List
    {
        for(int i = 1; i < pos-1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteNodeAtPos(int pos, Node *headpointer) 
{
    Node* temp = headpointer;
    int NoOfElements = 0;

    if(temp != NULL) {
        NoOfElements++;
        temp = temp->next;
    }
    while(temp != headpointer) {
        NoOfElements++;
        temp = temp->next;
    }

    if(pos < 1 || pos > (NoOfElements+1)) //NoOfElements is only calculated to check if the given position is valid or not
    {
        cout<<"\nInavalid position.";
    } 
    else if (pos == 1) 
    {
        if(headpointer->next == headpointer) //only head pointer exists 
        {
            headpointer = NULL;
        } 
        else 
        {
            while(temp->next != headpointer)// Loop to the last element of the linked list
            {
                temp = temp->next;
            }
            headpointer = headpointer->next; //Make the second element of the linked list as the new head pointer
            temp->next = headpointer; //make a connection between the temp pointer (last element of the linked list) and the new head pointer
        }
    }
    else //same as singly Linked List
    {
        for(int i=1; i<pos-1; i++) {
            if(temp != NULL) {
                temp = temp->next;
            }
        }

        //Node *NodeToBeDeleted = temp->next;
        temp->next = temp->next->next;
        //free(NodeToBeDeleted);
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
    second->next = head;

    // addNodeAtEnd(4, head);

    addNodeAtPos(8, 4, head);

    deleteNodeAtPos(4, head);

    printLinkedList(head);

    // int returnedValue = searchElement(1, head); // search the element at 4th index

    // cout << "\n"
    //      << returnedValue;

    return 0;
}