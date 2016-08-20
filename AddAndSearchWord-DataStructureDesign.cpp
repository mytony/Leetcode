// The class TrieNode is copied from 208. Implement Trie (Prefix Tree)
// Also reference:
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

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p = root;
        for (auto c: word) {
            if (!p -> next[c - 'a']) {
                p -> next[c - 'a'] = new TrieNode();
            }
            p = p -> next[c - 'a'];
        }
        p -> isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return query(word, root);
    }
    
private:
    TrieNode *root;
    
    bool query(string word, TrieNode* node) {
        TrieNode *p = node;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (p -> next[j] && query( word.substr(i+1), p -> next[j] ) ) {
                        return true;
                    }
                }
                return false; // necessary
            } else {
                if (!p -> next[word[i] - 'a']) {
                    return false;
                }
                p = p -> next[word[i] - 'a'];
            }
        }
        return p -> isWord;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");