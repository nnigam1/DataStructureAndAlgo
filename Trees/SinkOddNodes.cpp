
#include<iostream>
#include<queue>
using namespace std;

// A binary tree node
struct Node
{
    int data;
    Node* left, *right;
};

// Helper function to allocates a new node
Node* newnode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Helper function to check if node is leaf node
bool isLeaf(Node *root)
{
    return (root->left == NULL && root->right == NULL);
}

// A recursive method to sink a tree with odd root
// This method assumes that the subtrees are already
// sinked. This method is similar to Heapify of
// Heap-Sort
void sink(Node *&root)
{
    // If NULL or is a leaf, do nothing
    if (root == NULL || isLeaf(root))
        return;

    // if left subtree exists and left child is even
    if (root->left && !(root->left->data & 1))
    {
        // swap root's data with left child and
        // fix left subtree
        swap(root->data, root->left->data);
        sink(root->left);
    }

        // if right subtree exists and right child is even
    else if(root->right && !(root->right->data & 1))
    {
        // swap root's data with right child and
        // fix right subtree
        swap(root->data, root->right->data);
        sink(root->right);
    }
}

// Function to sink all odd nodes to the bottom of binary
// tree. It does a postorder traversal and calls sink()
// if any odd node is found
Node* sinkOddNodes(Node* &root)
{
    // If NULL or is a leaf, do nothing
    if (root == NULL || isLeaf(root))
        return NULL;

    // Process left and right subtrees before this node
    sinkOddNodes(root->left);
    sinkOddNodes(root->right);

    // If root is odd, sink it
    if (root->data & 1)
        sink(root);
}

// Helper function to do Level Order Traversal of
// Binary Tree level by level. This function is used
// here only for showing modified tree.
void printLevelOrder(Node* root)
{
    queue<Node*> q;
    q.push(root);

    // Do Level order traversal
    while (!q.empty())
    {
        int nodeCount = q.size();

        // Print one level at a time
        while (nodeCount)
        {
            Node *node = q.front();
            cout<<node->data<<" ";
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }

        // Line separator for levels
        cout<<endl;
    }
}

// Driver program to test above functions
int main()
{
    /* Constructed binary tree is
            1
          /   \
         5      8
        / \   /  \
       2   4 9   10     */

    Node *root = newnode(1);
    root->left = newnode(5);
    root->right    = newnode(8);
    root->left->left = newnode(2);
    root->left->right = newnode(4);
    root->right->left = newnode(9);
    root->right->right = newnode(10);

    sinkOddNodes(root);

    printf("Level order traversal of modified tree\n");
    printLevelOrder(root);

    return 0;
}

