#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    char ch;
    bool isWord;
    unordered_map<char, Node*> childrens;
    
    Node(char ch){
        this->ch = ch;
        this->isWord = false;
    }
};


class Trie {
public:
    Node *root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new Node('\0');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = root;
        for(char ch : word){
            if(curr->childrens.count(ch) == 0)
                curr->childrens[ch] = new Node(ch);
            curr = curr->childrens[ch];
        }
        curr->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = root;
        for(char ch : word){
            if(curr->childrens.count(ch) == 0)
                return false;
            curr = curr->childrens[ch];
        }
        return curr->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curr = root;
        for(char ch : prefix){
            if(curr->childrens.count(ch) == 0)
                return false;
            curr = curr->childrens[ch];
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