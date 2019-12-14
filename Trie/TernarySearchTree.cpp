#include <iostream>
#include <vector>
using namespace std;

class TernaryNode {
public:
    char c;
    bool isEndOfWord;

    TernaryNode* left;
    TernaryNode* right;
    TernaryNode* equal;

    TernaryNode* getNode(char ch) {
        TernaryNode* node = new TernaryNode();
        node->isEndOfWord = false;
        node->c = ch;
        node->equal = NULL;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
};

class Ternary{
public:
    TernaryNode node;

    void insert( TernaryNode** root , string word , int index) {
        if( (*root) == NULL)
            (*root) = (*root)->getNode(word[index]);

        if( (*root)->c > word[index])
            insert(&(*root)->left , word , index);
        else if( (*root)->c < word[index])
            insert(&(*root)->right , word , index);
        else {
            if( index < word.length())
            {
                insert(&(*root)->equal , word, index+1);
            } else{
                (*root)->isEndOfWord = true;
            }
        }
    }

    bool search(TernaryNode* root , string word , int index) {
        if( root == NULL)
            return  false;
        if( index == word.length() && root->isEndOfWord == true)
            return true;
        if( word[index] < root->c)
            return search(root->left , word, index);
        else if( word[index] > root->c)
            return search(root->right , word , index);
        else
            return search(root->equal , word , index+1);
    }

    bool isEmpty(TernaryNode* node){
        if( node->left == NULL && node->right == NULL && node->equal == NULL)
            return true;
        return false;
    }

    TernaryNode* remove(TernaryNode* root , string word , int index) {
        if( root == NULL) {
            cout<<"item not found"<<endl;
            return NULL;
        }

        if(index == word.length() && root->isEndOfWord)
        {
            if( isEmpty(root)) {
                delete root;
                root = NULL;
            }
            else {
                root->isEndOfWord = false;
            }
            return root;
        }

        if( word[index] < root->c) {
            root->left = remove(root->left , word, index);
        }
        else if( word[index] > root->c){
            root->right = remove(root->right , word , index);
        }
        else {
            root->equal = remove(root->equal, word, index + 1);
        }

        if( isEmpty(root)) {
            delete root;
            root = NULL;
        }
        return root;
    }

};

int main() {
    Ternary* ternary = new Ternary();
    TernaryNode* root = NULL;
    ternary->insert(&root , "cat" , 0);
    ternary->insert(&root, "bugs" , 0 );
    ternary->insert(&root , "cats" , 0 );
    ternary->insert(&root , "up", 0 );

    ternary->search(root , "cats", 0 ) ? cout<<"Yes" : cout<< "No";
    cout<<endl;
    ternary->search(root , "bugs", 0) ? cout<<"Yes" : cout<< "No";
    cout<<endl;
    ternary->search(root , "neha", 0) ? cout<<"Yes" : cout<< "No";
    cout<<endl;

    root = ternary->remove(root , "cats" , 0);

    ternary->search(root , "cats", 0) ? cout<<"Yes" : cout<< "No";
    cout<<endl;

    return 0;
}






