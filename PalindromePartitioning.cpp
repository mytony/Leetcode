class Solution {
public:
    vector<vector<string>> res;
    vector<string> cur;
    
    vector<vector<string>> partition(string s) {
        backtrack(s, 0, 1);
        return res;
    }
    
    void backtrack(string s, int pos, int len) {
        
        if (pos == s.size()) {
            res.push_back(cur);
            return;
        }
        if (pos + len > s.size()) return;
        
        // If this element can be a palindrome so far, 
        // choose to find a next new palindrome
        if (isPalindrome(s.substr(pos, len))) {
            cur.push_back(s.substr(pos, len));
            backtrack(s, pos+len, 1);
            cur.pop_back();
        }
        
        // choose keep adding word to form a palindrome
        backtrack(s, pos, len+1);
    }
    
    bool isPalindrome(string s) {
        if (s.size() == 1) return true;
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev ? true : false;
    }
};