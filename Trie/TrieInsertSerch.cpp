#include <iostream>
#include <vector>
using namespace std;

class TrieNode {

public:

    TrieNode* trieNode[26];
    bool isEndOfWord;

    TrieNode* getNode()
    {
        TrieNode* temp = new TrieNode();
        for( int i = 0 ; i< 26 ; i++)
            temp->trieNode[i] = NULL;
        temp->isEndOfWord = false;
        return temp;
    }

    ~TrieNode() {
        for(int i = 0 ; i < 26 ; i++)
        {
            delete trieNode[i];
        }
    }
};

class Trie {
    TrieNode* node;
public:
    void insert(TrieNode* root , string key);
    bool search(TrieNode* root , string key);
};

void Trie::insert(TrieNode* root , string key) {
    TrieNode* pCrawl = root;
    for( int i = 0 ; i < key.length() ; i++)
    {
        if( pCrawl->trieNode[key[i] - 'a'] == NULL) {
            pCrawl->trieNode[key[i] - 'a'] = pCrawl->getNode();
        }
        pCrawl = pCrawl->trieNode[key[i] - 'a'];
    }
    pCrawl->isEndOfWord = true;
}

bool Trie::search(TrieNode* root , string key) {
    TrieNode* pCrawl = root;
    int i = 0;
    for(  ; i < key.length() ; i++) {
        if( pCrawl->trieNode[key[i] - 'a'] != NULL) {
            pCrawl = pCrawl->trieNode[key[i] - 'a'];
        }
        else {
            return false;
        }
    }
    if( i == key.length()) {
        if(pCrawl->isEndOfWord == true)
            return true;
        else
            return false;
    }
    return false;
}

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


    return 0;
}