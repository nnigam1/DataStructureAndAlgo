#include<iostream>
#include<vector>
using namespace std;

class TrieNode {
public:
    bool isEndOfWord;
    vector<TrieNode*> trieNode;

    TrieNode()
    {
        isEndOfWord = false;
    }

    TrieNode* getNode()
    {
       TrieNode* node = new TrieNode();
       for(int i = 0 ; i < 26 ; i++)
       {
           node->trieNode.push_back(NULL);
       }
       node->isEndOfWord = false;
       return node;
    }

};

class Trie {
public:
    TrieNode* trieNode;
    void insert(TrieNode* root , string key) {
        TrieNode* pCrawl = root;
        for( int i = 0 ; i< key.length() ; i++)
        {
            int index = key[i] - 'a';
            if( pCrawl->trieNode[index] == NULL ){
                pCrawl->trieNode[index] = pCrawl->getNode();
            }
            pCrawl = pCrawl->trieNode[index];
        }
        pCrawl->isEndOfWord = true;
    }

    bool search(TrieNode* root , string key)
    {
        TrieNode* pCrawl = root;
        int i = 0;
        for( ;i < key.length() ; i++) {
            int index = key[i] - 'a';
            if( pCrawl->trieNode[index] != NULL)
                pCrawl = pCrawl->trieNode[index];
            else
                return false;
        }
        if( i == key.length() && pCrawl->isEndOfWord == true) {
            return true;
        }
        return false;
    }

    bool isEmpty(TrieNode* root) {
        for( int i = 0 ; i < 26 ; i++) {
            if( root->trieNode[i] != NULL) {
                return false;
            }
        }
        return true;
    }

    TrieNode* remove(TrieNode* root , string key , int depth) {
        if( root == NULL)
        {
            return NULL;
        }

        if( key.length() == depth) {
            if( root->isEndOfWord == true) {
                root->isEndOfWord = false;
            }

            else {
                if( isEmpty(root)) {
                    delete root;
                    root = NULL;
                }
            }
            return root;
        }
        int index = key[depth] - 'a';

        root->trieNode[index] = remove(root->trieNode[index] , key , depth+1 );

        if( isEmpty(root)) {
            delete root;
            root = NULL;
        }
        return root;
    }
};

int main() {
    TrieNode* node = new TrieNode();
    TrieNode* root = node->getNode();
    string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
    Trie* trie = new Trie();

    for( int i = 0 ; i < n ; i++)
    {
        trie->insert(root, keys[i]);
    }

    // Search for different keys
    trie->search(root, "the")? cout << "Yes\n" :
    cout << "No\n";

    trie->search(root, "answer")? cout << "Yes\n" :
    cout << "No\n";

    root = trie->remove(root , "answer" , 0);

    trie->search(root, "answer")? cout << "Yes\n" :
    cout << "No\n";

    return 0;
}