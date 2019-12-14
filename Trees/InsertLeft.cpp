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
        left = NULL;
        right = NULL;
    };
};

node* getNode(int key )
{
    node* newNode = new node(key);
}

node* insert(node* root , int key , int left)
{
    if( root == NULL)
    {
        root = getNode(key);
        return root;
    }

    if( root->data > key)
    {
        root->left = insert(root->left , key , left+1);
        root->lCount = left;
    } else if (root->data < key)
    {
        root->right = insert(root->right , key , left);

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
        root = insert(root , ele[i] , 0);
    }
    inOrder(root);
    return 0;
}
