class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Use an array to store the numbers of letters that appears
        vector<int> dict(26, 0);
        for (char c: magazine) {
            dict[c-'a']++;
        }
        
        for (char c: ransomNote) {
            if (dict[c-'a'] == 0) {
                return false;
            }
            dict[c-'a']--;
        }
        
        return true;
    }
};