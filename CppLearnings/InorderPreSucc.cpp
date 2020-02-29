#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node* right;
};

Node* getNode(int x)
{
    Node* n = new Node();
    n->data = x;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* insert(Node* root , int data)
{
    if(root == NULL)
        return getNode(data);

    if (root->data > data) {
        root->left = insert(root->left, data);
    } else
        root->right = insert(root->right, data);
    return root;
}

void findPreSuc(Node* root , Node*& pre , Node*& suc , int key) {
    if( root == NULL)
        return;
    if( root->data == key) {
        if( root->left != NULL)
        {
            Node* temp = root->left;
            while(temp->right)
                temp = temp->right;
            pre = temp;
        }
        if( root->right != NULL){
            Node* temp = root->right;
            while( temp->left)
                temp = temp->left;
            suc = temp;
        }
        return;
    }
    if( root->data > key) {
        suc = root;
        findPreSuc(root->left , pre , suc , key);
    } else {
        pre = root;
        findPreSuc(root->right , pre , suc , key);
    }
    return;
}

int main()
{
    int key = 40;
    Node* root = NULL;
    root = insert(root , 50);
    insert(root , 30);
    insert(root , 20);
    insert(root , 40);
    insert(root , 90);
    insert(root , 60);
    insert(root , 80);

    Node* pre = NULL , *suc = NULL;
    findPreSuc(root , pre , suc , key);
    if( pre != NULL) {
        cout << pre->data << endl;
    }
    else{
        cout<<"pre is NULL"<<endl;
    }
    if( suc != NULL) {
        cout<<suc->data<<endl;
    }
    else{
        cout<<"suc is NULL"<<endl;
    }
    return 0;
}