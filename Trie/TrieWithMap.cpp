#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode {
public:
    bool isEndOfWord;
    unordered_map<char , TrieNode*> trieNode;

    TrieNode () {
        isEndOfWord = false;
        trieNode.reserve(26);
    }

    TrieNode* getNode() {
        TrieNode* node = new TrieNode();
        node->isEndOfWord = false;
        return node;
    }
};

class Trie {
public:
    TrieNode* node;
    void insert(TrieNode* root , string key) {
        TrieNode* pCrawl = root;
        for( int i = 0 ; i < key.length() ; i++) {
            if( pCrawl->trieNode.find(key[i]) == pCrawl->trieNode.end()) {
                pCrawl->trieNode[key[i]] = pCrawl->getNode();
            }
            pCrawl = pCrawl->trieNode[key[i]];
        }

        pCrawl->isEndOfWord = true;
    }

    bool search(TrieNode* root, string key) {
        TrieNode* pCrawl = root;
        if( root == NULL){
            return false;
        }

        int i = 0 ;
        for( ; i < key.length() ; i++) {
            if( pCrawl->trieNode.find(key[i]) == pCrawl->trieNode.end())
            {
                return false;
            } else{
                pCrawl = pCrawl->trieNode[key[i]];
            }
        }

        if( i == key.length() && pCrawl->isEndOfWord == true) {
            return true;
        }
        return false;
    }

    bool isEmpty(TrieNode* root){
        if( root->trieNode.size() == 0)
            return true;
        return false;
    }

    TrieNode* remove(TrieNode* root , string key , int depth) {
        if( root == NULL)
            return NULL;

        if( depth == key.length()) {
            if( root->isEndOfWord == true)
                root->isEndOfWord = false;
            if( isEmpty(root))
            {
                root->trieNode.erase(key[depth]);
            }
            return root;
        }

        root->trieNode[key[depth]] = remove(root->trieNode[key[depth]] , key , depth+1);

        if(isEmpty(root->trieNode[key[depth]])) {
            root->trieNode.erase(key[depth]);
        }
        return root;
    }
};

int main() {
    TrieNode* node = new TrieNode();
    if( node->trieNode.size() == 0)
        cout<<"size is 0 "<<endl;
    cout<< sizeof(node->trieNode)<<endl;

    cout<< sizeof(node)<<endl;
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

    trie->search(root, "any")? cout << "Yes\n" :
    cout << "No\n";

    trie->remove(root, "answer" , 0);

    trie->search(root, "answer")? cout << "Yes\n" :
    cout << "No\n";


    return 0;
}

