#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// a 5 , b 9 , c 12 , d 13 , e 16 , f 45

class TreeNode
{
public:
    int freq;
    TreeNode* left;
    TreeNode* right;
    char data;

    TreeNode(int x)
    {
        data = x ;
        left = NULL;
        right = NULL;
    }

    TreeNode* getNode(int x)
    {
        TreeNode* t = new TreeNode(x);
        return t;
    }
};

void printArr(int top , vector<int> arr)
{
    for(int i = 0 ; i < top ; i++) {
        cout<<arr[i];
    }
    cout<<endl;
}

void traverse(TreeNode* root , int top , vector<int> arr)
{
    if(root->left)
    {
        arr[top] = 0;
        traverse(root->left , top+1 , arr);
    }

    if( root->right)
    {
        arr[top] = 1;
        traverse(root->right , top+1 , arr);
    }

    if( root->left == NULL && root->right == NULL)
    {
        cout<<root->data<<" ";
        printArr(top , arr);
    }
}

void HuffManCoding(char vec[] , int freq[] , int n)
{
    vector<int> arr(100);
    auto myLambda = [](const TreeNode* a , const TreeNode* b) {
        return (a->freq > b->freq);
    };
    priority_queue<TreeNode*, vector<TreeNode*> , decltype(myLambda) > pq(myLambda);
    for(int i = 0 ; i<n ; i++)
    {
        TreeNode* node = new TreeNode(vec[i]);
        node->freq = freq[i];
        pq.push(node);
    }

    TreeNode* root = NULL;

    while(pq.size() != 1) {
        TreeNode *left1 = pq.top();
        pq.pop();
        TreeNode *right1 = pq.top();
        pq.pop();

        TreeNode* node = new TreeNode('$');
        node->left = left1;
        node->right = right1;
        node->freq = left1->freq + right1->freq;

        pq.push(node);
    }
    if( pq.size() == 1) {
        root = pq.top();
        pq.pop();
    }
    traverse(root , 0 , arr);
}

int main()
{
    char arr[] = {'a' , 'b' , 'c' , 'd' , 'e' , 'f'};
    int freq[] = {5 , 9 , 12, 13, 16 , 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    HuffManCoding(arr , freq , n);
    return 0;
}

