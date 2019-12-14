// C++ implementation to print the path common to the
// two paths from the root to the two given nodes
#include<iostream>
#include<queue>
using namespace std;

// structure of a node of binary tree
struct Node
{
    int data;
    Node *left, *right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct Node* getNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// This function returns pointer to LCA of two given values n1 and n2.
// v1 is set as true by this function if n1 is found
// v2 is set as true by this function if n2 is found
struct Node *findLCAUtil(struct Node* root, int n1, int n2, bool &v1, bool &v2)
{
    // Base case
    if (root == NULL) return NULL;

    // If either n1 or n2 matches with root's data, report the presence
    // by setting v1 or v2 as true and return root (Note that if a key
    // is ancestor of other, then the ancestor key becomes LCA)
    if (root->data == n1)
    {
        v1 = true;
        return root;
    }
    if (root->data == n2)
    {
        v2 = true;
        return root;
    }

    // Look for nodes in left and right subtrees
    Node *left_lca = findLCAUtil(root->left, n1, n2, v1, v2);
    Node *right_lca = findLCAUtil(root->right, n1, n2, v1, v2);

    // If both of the above calls return Non-NULL, then one node
    // is present in one subtree and other is present in other,
    // So this current node is the LCA
    if (left_lca && right_lca) return root;

    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL)? left_lca: right_lca;
}

// Returns true if key k is present in tree rooted with root
bool find(Node *root, int k)
{
    // Base Case
    if (root == NULL)
        return false;

    // If key k is present at root, or in left subtree
    // or right subtree, return true
    if (root->data == k || find(root->left, k) || find(root->right, k))
        return true;

    // Else return false
    return false;
}

// This function returns LCA of n1 and n2 only if both n1 and n2
// are present in tree, otherwise returns NULL
Node *findLCA(Node *root, int n1, int n2)
{
    // Initialize n1 and n2 as not visited
    bool v1 = false, v2 = false;

    // Find lca of n1 and n2
    Node *lca = findLCAUtil(root, n1, n2, v1, v2);

    // Return LCA only if both n1 and n2 are present in tree
    if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))
        return lca;

    // Else return NULL
    return NULL;
}

// function returns true if
// there is a path from root to
// the given node. It also populates
// 'arr' with the given path
bool hasPath(Node *root, deque<int>& arr, int x)
{
    // if root is NULL
    // there is no path
    if (!root)
        return false;

    // push the node's value in 'arr'


    // if it is the required node
    // return true
    if (root->data == x)
    {
        arr.push_back(x);
        return true;

    }
    // else check whether there the required node lies in the
    // left subtree or right subtree of the current node
    if (hasPath(root->left, arr, x) ||
        hasPath(root->right, arr, x))
    {
        arr.push_back(root->data);
        return true;
    }

    // required node does not lie either in the
    // left or right subtree of the current node
    // Thus, remove current node's value from 'arr'

    return false;
}

// function to print the path common
// to the two paths from the root
// to the two given nodes if the nodes
// lie in the binary tree
void printCommonPath(Node *root, int n1, int n2)
{
    // vector to store the common path
    deque<int> arr;

    // LCA of node n1 and n2
    Node *lca = findLCA(root, n1, n2);

    // if LCA of both n1 and n2 exists
    if (lca)
    {
        // then print the path from root to
        // LCA node
        if (hasPath(root, arr, lca->data))
        {
            int lcaVal = lca->data;
            int sum = 0;
          for_each(arr.rbegin() , arr.rend() , [arr , lcaVal , &sum ](const int i) {
              sum +=i;
          });
          cout<<sum;
        }
    }

        // LCA is not present in the binary tree
        // either n1 or n2 or both are not present
    else
        cout << "No Common Path";
}

// Driver program to test above
int main()
{
    // binary tree formation
    struct Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->left = getNode(6);
    root->right->right = getNode(7);
    root->left->right->left = getNode(8);
    root->right->left->right = getNode(9);

    int n1 = 5, n2 = 8;
    printCommonPath(root, n1, n2);
    return 0;
}


