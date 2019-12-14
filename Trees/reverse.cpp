#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

// A Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Reverse Tree path
Node* reverseTreePath(Node* root, int data , int* arr ,int index , deque<int>& dq)
{
    if( root == NULL)
        return NULL;

    //  cout<<root->data<<" ";

    if( root->data == data) {
        arr[index] = root->data;
        for(int i = 0 ; i <= index ; i++) {
            dq.emplace_back(arr[i]);
        }
        swap(root->data , dq.front());
        dq.pop_front();
        return root;
    }

    //  cout<<root->data<<" ";

    arr[index] = root->data;
    Node* left = reverseTreePath(root->left , data , arr , index+1 , dq);
    Node* right = reverseTreePath(root->right , data , arr , index+1 , dq);

    if( left != NULL || right != NULL)
    {
        if( left != NULL) {
            swap(root->data, dq.front());
            dq.pop_front();
        }
        else {
            swap(root->data, dq.front());
            dq.pop_front();
        }

        return root;
    }

    return NULL;

}

// INORDER
void inorder(Node* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    deque<int> vec;
    // Let us create binary tree shown in above diagram
    Node* root = newNode(7);
    root->left = newNode(6);
    root->right = newNode(5);
    root->left->left = newNode(4);
    root->left->right = newNode(3);
    root->right->left = newNode(2);
    root->right->right = newNode(1);

    /*	 7
        / \
        6	 5
    / \	 / \
    4 3	 2 1		 */

    int data = 4;
    int arr[100] = {0};

    //cout<<"start";
    // Reverse Tree Path
    root = reverseTreePath(root, data ,arr , 0 , vec);

    // Traverse inorder
    inorder(root);
    return 0;
}


