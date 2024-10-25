public class Main {
    public static void main(String[] args) {
        Trie trie = new Trie();

        trie.insert("parthi");
        trie.insert("part");
        trie.insert("park");
        trie.insert("parking");

        System.out.println(trie.search("parth"));  // false
        System.out.println(trie.doesExistWordStartWith("par"));  // true
        
        // Traverse the entire Trie
        trie.traverse();
    }
}

class TrieNode {
    public boolean isWord;
    public TrieNode[] children;

    TrieNode() {
        isWord = false;
        children = new TrieNode[26];
    }
}

class Trie {
    public TrieNode root;

    Trie() {
        root = new TrieNode();
    }

    public void insert(String str) {
        TrieNode curr = root;
        for (char ch : str.toCharArray()) {
            if (curr.children[ch - 'a'] == null)
                curr.children[ch - 'a'] = new TrieNode();
            curr = curr.children[ch - 'a'];
        }
        curr.isWord = true;
    }

    public boolean search(String str) {
        TrieNode curr = root;
        for (char ch : str.toCharArray()) {
            if (curr.children[ch - 'a'] == null)
                return false;
            curr = curr.children[ch - 'a'];
        }
        return curr.isWord;
    }

    public boolean doesExistWordStartWith(String str) {
        TrieNode curr = root;
        for (char ch : str.toCharArray()) {
            if (curr.children[ch - 'a'] == null)
                return false;
            curr = curr.children[ch - 'a'];
        }
        return true;
    }

    public void traverse() {
        List<String> words = new ArrayList<>();
        dfs(root, new StringBuilder(), words);
        for (String word : words) {
            System.out.println(word);
        }
    }

    private void dfs(TrieNode node, StringBuilder prefix, List<String> words) {
        if (node == null) {
            return;
        }
        if (node.isWord) {
            words.add(prefix.toString());
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (node.children[c - 'a'] != null) {
                prefix.append(c);
                dfs(node.children[c - 'a'], prefix, words);
                prefix.deleteCharAt(prefix.length() - 1); // Backtrack
            }
        }
    }
}
