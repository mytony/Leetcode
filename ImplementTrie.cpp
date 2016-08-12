// Forum solution
// https://discuss.leetcode.com/topic/13463/maybe-the-code-is-not-too-much-by-using-next-26-c
// Solution from follow-up question
// https://discuss.leetcode.com/topic/15581/80ms-clear-c-code-with-detailed-explanations
class TrieNode {
public:
    TrieNode *next[26];
    bool isWord;
    
    // Initialize your data structure here.
    TrieNode(bool b = false) {
        memset(next, NULL, sizeof(next));
        isWord = b;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for (auto c: word) {
            if (!p -> next[c - 'a']) {
                p -> next[c - 'a'] = new TrieNode();
            }
            p = p -> next[c - 'a'];
        }
        p -> isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = find(word);
        return p != NULL && p -> isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = find(prefix);
        
        // We can return true for sure because that this pointer is not NULL
        // means p->isWord may be true or one of the 26 pointers in the array
        // might be not NULL so that this pointer has been newed a space
        return p != NULL;
    }

private:
    TrieNode* root;
    
    TrieNode* find(string key) {
        TrieNode *p = root;
        
        for (auto c: key) {
            if (!p -> next[c - 'a']) {
                return NULL;
            }
            p = p -> next[c - 'a'];
        }
        return p;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");