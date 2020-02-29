#include<iostream>
#include<map>
using namespace std;

class Trie {
        int eow;
        map<char , Trie*> mp;

        public:
        Trie() : eow(0) {};

        void insert(string str) {
            Trie* temp = this;
            int len = str.length();
            for(int i = 0 ; i < len ; i++) {
                if( temp->mp.find(str[i]) == temp->mp.end()) {
                    temp->mp[str[i]] = new Trie();
                }
                temp = temp->mp[str[i]];
                if( i == len-1 ) {
                    temp->eow +=1;
                }
            }
        }

        bool search( string str) {
            Trie* temp = this;
            int len = str.length();
            for(int i = 0; i < len ; i++) {
                if( temp->mp.find(str[i]) != temp->mp.end()) {
                    temp = temp->mp[str[i]];
                } else {
                    return false;
                }
                if( i == len -1 && temp->eow > 0 ) {
                    return true;
                    }
                }
            return false;
        }

        bool regexSearch(string str) {

        }
};

int main() {
    Trie* root = new Trie();
    root->insert("bad");
    root->insert("cat");
    root->insert("dad");

    cout<<root->search("bad")<<endl;
    cout<<root->search("cats")<<endl;
    cout<<root->search("dad")<<endl;
    return 0;

}

//class WordDictionary {
//public:
//    /** Initialize your data structure here. */
//    WordDictionary() {
//
//    }
//
//    /** Adds a word into the data structure. */
//    void addWord(string word) {
//
//
//    }
//
//    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
//    bool search(string word) {
//
//    }
//};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
