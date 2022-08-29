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

void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        cout << " " << root->data;
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node *root)
{
    if (root != NULL)
    {
        cout << " " << root->data;
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << " " << root->data;
    }
}

void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

int main()
{
    Node *root = buildtree();
    print(root);

    cout << "\n\nInorder Traversal\n";
    inorderTraversal(root);
    cout << "\nPreorder Traversal\n";
    preorderTraversal(root);
    cout << "\nPostorder Traversal\n";
    postorderTraversal(root);

    return 0;
}