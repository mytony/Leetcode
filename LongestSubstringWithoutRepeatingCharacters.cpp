class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Starting from the front of the string,
        // form a longest window without repeating chars
        // Move right by a character at a time
        // Check if there are duplicate character and 
        // if it's possible to expand the size of window
        
        int start = 0, end = 0;
        int longest = 0;
        unordered_set<char> charTable;
        
        // find the longest window from the start
        // in the end, the value is the position not valid one
        while (end < s.size()) {
            // the next character will not cause duplicate
            // The window can contain it
            if (charTable.find(s[end]) == charTable.end()) {
                charTable.insert(s[end]);
                end++;
                continue;
            } else {
                longest = max(longest, end-start);
                // move entire window to the right by 1
                charTable.erase(s[start]);
                start++;
            }
        }
        
        longest = max(longest, end-start);
        return longest;
        
    }
};