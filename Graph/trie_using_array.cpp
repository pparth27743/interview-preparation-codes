#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    bool isWord = false;
    // vector<Node*> children;
    Node *children[26] = {};
        
    Node(){
        this->isWord = false;
        // this->children.resize(26);
    }
};


class Trie {
public:
    Node *root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *curr = root;
        for(char ch : word){
            if(curr->children[ch-'a'] == nullptr)
                curr->children[ch-'a'] = new Node();
            curr = curr->children[ch-'a'];
        }
        curr->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *curr = root;            
        for(char ch : word){
            if(curr->children[ch-'a'] == nullptr)
                return false;
            curr = curr->children[ch-'a'];
        }
        return curr->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *curr = root;
        for(char ch : prefix){
            if(curr->children[ch-'a'] == nullptr)
                return false;
            curr = curr->children[ch-'a'];
        }
        return true;
    }
};


int main(){

  Trie* obj = new Trie();

    obj->insert("parth");
    cout << obj->search("Parth") << endl; 
    cout << obj->startsWith("parth") << endl;

    cout << obj->search("part") << endl; 
    cout << obj->startsWith("par") << endl;


    return 0;
}