#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d) // parameterized constructor
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *buildtree() // inserting values in tree using recursion
{
    int d;
    Node *root;
    cout << "Enter value of node (Enter -1 to stop insertion)\n";
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    root = new Node(d);
    cout << "Enter value to the left of " << d << " node (Enter -1 to stop insertion)\n";
    root->left = buildtree();
    cout << "Enter value to the right of " << d << " node (Enter -1 to stop insertion)\n";
    root->right = buildtree();
    return root;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (1 + max(leftHeight, rightHeight));
}

void printTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    Node *root = buildtree();
    printTree(root);

    int h = height(root);
    cout << "\n"
         << h;
}