public class Main {
    public static void main(String[] args) {
        Trie trie = new Trie();
        
        trie.insert("parthi");
        System.out.println(trie.search("parth"));
        System.out.println(trie.doesExistWordStartWith("par"));
    }
}


class TrieNode {
    public boolean isWord;
    public TrieNode[] children;
    
    TrieNode() {
        isWord = false;
        children = new TrieNode[26];
    }    
};

class Trie{
    public TrieNode root;
    
    Trie() {
        root = new TrieNode();
    }
    
    public void insert(String str) {
        TrieNode curr  = root;
        for(char ch : str.toCharArray()) {
            if(curr.children[ch - 'a'] == null)
                curr.children[ch - 'a'] = new TrieNode();
            curr = curr.children[ch - 'a'];
        }
        curr.isWord = true;
    }
    
    public boolean search(String str) {
        TrieNode curr = root;
        for(char ch : str.toCharArray()) {
            if(curr.children[ch - 'a'] == null)
                return false;
            curr = curr.children[ch - 'a'];
        }
        return curr.isWord;
    }
    
    public boolean doesExistWordStartWith(String str) {
        TrieNode curr = root; 
        for(char ch : str.toCharArray()) {
            if(curr.children[ch - 'a'] == null)
                return false;
            curr = curr.children[ch - 'a'];
        }
        return true;
    }

};


