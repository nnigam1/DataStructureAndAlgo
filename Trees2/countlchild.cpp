#include<iostream>
#include<climits>
using namespace std;

// A BST node
struct Node
{
    int key;
    int lCount;
    Node *left, *right;
};

// A function to find
int countLeftChild(Node *root, bool isLeft)
{
    if( root == NULL)
        return 0;

    int l = countLeftChild(root->left , true);
    int r = countLeftChild(root->right , false);
    if(isLeft)
    {
        root->lCount = l+r;
        return root->lCount+1;
    }
        root->lCount = l;
        return l;
}

// A utility function to create a new BST node
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->lCount = 0;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

void inOrder(Node* root)
{
    if( root == NULL )
        return;
    inOrder(root->left);
    cout<<root->key<<" "<<root->lCount<<" "<<endl;
    inOrder(root->right);
}

// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 10);
    insert(root, 75);



   cout<< countLeftChild(root , true);

    cout<<"inorder"<<endl;
    inOrder(root);
    return 0;
}

