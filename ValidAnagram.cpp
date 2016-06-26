
class Solution {
public:
    // Sort each string and compare
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t)
            return true;
        else
            return false;
    }
};