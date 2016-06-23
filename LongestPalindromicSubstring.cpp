// looked forum
// Not divide into two odd and even cases
// https://leetcode.com/discuss/32204/simple-c-solution-8ms-13-lines
// Handle two situations separately
// https://leetcode.com/discuss/56323/very-simple-clean-java-solution
class Solution {
public:
    string longestPalindrome(string s) {
        maxLen = start = 0;
        
        for (int i = 0; i < s.size(); i++) {
            extendPalindrome(s, i, i); // odd palindrome
            extendPalindrome(s, i, i+1); // even palindrome
        }
        
        return s.substr(start, maxLen);
    }
private:
    int start, maxLen;
    void extendPalindrome(string& s, int i, int j) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        
        if ((j-1) - (i+1) + 1 > maxLen) {
            start = i + 1;
            maxLen = (j-1) - (i+1) + 1;
        }
    }
};