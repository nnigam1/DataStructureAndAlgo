// C++ implementation of a O(n) time method for spiral order traversal
#include <iostream>
#include <queue>
#include<stack>

using namespace std;

// Binary Tree node
struct node {
    int data;
    struct node *left, *right;
};

void printSpiral(struct node* root)
{
   deque<node*> q;
   stack<node*> stk;

   q.push_back(root);
   //int n = dq.size();
   int level = 1;

    while (!q.empty())
    {
        // nodeCount indicates number of Nodes
        // at current level.
        int nodeCount = q.size();

        // Dequeue all Nodes of current level and
        // Enqueue all Nodes of next level
        if (level&1)    //odd level
        {
            while (nodeCount > 0)
            {
                // dequeue node from front & push it to
                // stack
                node *temp = q.front();
                q.pop_front();
                cout<<temp->data<<" ";
                stk.push(temp);

                // insert its left and right children
                // in the back of the deque
                if (temp->left != NULL)
                    q.push_back(temp->left);
                if (temp->right != NULL)
                    q.push_back(temp->right);

                nodeCount--;
            }
        }
        else      //even level
        {
            while (nodeCount > 0)
            {
                // dequeue node from the back & push it
                // to stack
                node *temp = q.back();
                q.pop_back();
                cout<<temp->data<<" ";
                stk.push(temp);

                // inserts its right and left children
                // in the front of the deque
                if (temp->right != NULL)
                    q.push_front(temp->right);
                if (temp->left != NULL)
                    q.push_front(temp->left);
                nodeCount--;
            }
        }
        level++;
    }


}

// A utility function to create a new node
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout << "Spiral Order traversal of binary tree is \n";
    printSpiral(root);

    return 0;
}

