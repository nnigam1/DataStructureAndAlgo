#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/* Utility function to create a new Binary Tree node */
struct Node* newNode(int data)
{
    struct Node* temp = new struct Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void eulerTour(Node* root , vector<int>& euler) {
    if(root == NULL)
        return;

    euler.push_back(root->data);
    if( root->left ) {
        eulerTour(root->left, euler);
        euler.push_back(root->data);
    }
    if( root->right) {
        eulerTour(root->right, euler);
        euler.push_back(root->data);
    }
}

void printEulerTour(Node* root)
{
    vector<int> euler;
    eulerTour(root , euler);

    for(auto itr : euler) {
        cout<<itr<<" ";
    }
    cout<<endl;
}

int main()
{
    // Constructing tree given in the above figure
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    // print Euler Tour
    printEulerTour(root);

    return 0;
}

