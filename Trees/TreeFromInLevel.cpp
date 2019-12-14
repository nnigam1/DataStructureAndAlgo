#include <iostream>
#include<set>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/* A binary tree node */
struct Node
{
    int key;
    struct Node* left, *right;
};

Node* makeNode(int data){
    Node* newNode = new Node();
    newNode->key = data;
    newNode->right = newNode->right = NULL;
    return newNode;
}

// Function to build tree from given
// levelorder and inorder
Node* buildTree(unordered_map<int , int> inMap, int inorder[], vector<int> levelOrder,
                int iStart, int iEnd, int n)
{
    if( iStart > iEnd)
        return NULL;

    // First node of level order is root
    Node* root = makeNode(levelOrder[0]);

    if(iStart == iEnd)
        return root;

    int index = -1;
    if(inMap.find(levelOrder[0]) != inMap.end())
    {
        index = inMap[levelOrder[0]];
    }

    int li = 0 , ri = 0;
    // Separate level order traversals
    // of left and right subtrees.
    vector<int> lLevel(index - iStart);// Left
    vector<int> rLevel(iEnd - index);// Left

    for( int i = iStart ; i < index ; i++)
    {
        lLevel[li++] = inorder[i];
    }

    for( int i = index + 1 ; i <= iEnd ; i++)
    {
        rLevel[ri++] = inorder[i];
    }
    // Recursively build left and right
    // subtrees and return root.
    root->left = buildTree(inMap , inorder, lLevel,
                           iStart, index-1, index-iStart);
    root->right = buildTree(inMap , inorder, rLevel,
                            index+1, iEnd, iEnd-index);
    return root;

}

/* Utility function to print inorder
traversal of binary tree */
void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->key << " ";
    printInorder(node->right);
}

void fillInorderInMap(int in[] , unordered_map<int ,int>& inMap , int n)
{
    for( int i = 0 ; i< n ; i ++)
    {
        inMap[in[i]] = i;
    }
}

// Driver Code
int main()
{
    int in[] = {4, 8, 10, 12, 14, 20, 22};
    vector<int> level = {20, 8, 22, 4, 12, 10, 14};
    unordered_map<int ,int> inMap;

    int n = sizeof(in)/sizeof(in[0]);

    fillInorderInMap(in , inMap , n);

    Node *root = buildTree(inMap, in ,  level, 0,
                           n - 1, n);
    /* Let us test the built tree by
    printing Insorder traversal */
    cout << "Inorder traversal of the "
            "constructed tree is \n";
    printInorder(root);

    return 0;
}


