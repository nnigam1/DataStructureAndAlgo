/* C++ program to calculate Kth ancestor of given node */
#include <iostream>
#include <queue>
using namespace std;

// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};

// temporary node to keep track of Node returned
// from previous recursive call during backtrack
Node* temp = NULL;

// recursive function to calculate Kth ancestor
bool kthAncestorDFS(Node *root, int node , int& k )
{
    // Base case
    if (!root)
        return false;

    if( root->data == node)
    {
        --k;
        return true;
    }
    if ((kthAncestorDFS(root->left,node,k)) ||
        (kthAncestorDFS(root->right,node,k) ))
    {
       if( k > 0)
           --k;
       else if( k == 0 )
       {
           cout<<root->data;
       }
        return true;
    }
    return false;
}

// Utility function to create a new tree node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int k = 2;
    int node = 5;
    int level =0;
    // print kth ancestor of given node
    if(!kthAncestorDFS(root,node,k))
    {
        cout<<"-1";
    }
    return 0;
}

