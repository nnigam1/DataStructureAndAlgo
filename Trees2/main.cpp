#include<iostream>
using namespace std;

class node
{
public:
    int data;
    int lCount;
    node* left;
    node* right;

    node(int data) : data(data)  {
        lCount = 0;
        left = NULL;
        right = NULL;
    };
};

node* getNode(int key )
{
    node* newNode = new node(key);
    return newNode;
}

node* insert(node* root , int key)
{
    if( root == NULL)
    {
        root = getNode(key);
        return root;
    }

    if( root->data > key)
    {
        root->left = insert(root->left , key );
        root->lCount++;
    } else if (root->data < key)
    {
        root->right = insert(root->right , key);
    }
    return root;
}

void inOrder(node* root)
{
    if( root == NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" "<<root->lCount<<" "<<endl;
    inOrder(root->right);
}

int main()
{
    int ele[] = { 20, 8, 22, 4, 12, 10, 14 };
    cout<<"hello";
    int n = sizeof(ele) / sizeof(ele[0]);
    node* root = NULL;
    for(int i = 0 ; i< n ; i++ )
    {
        root = insert(root , ele[i] );
    }
    inOrder(root);
    return 0;
}

