// There are many solutions other than mine
// My solution is not a in-place solution
// I'm not sure if it's good
class Solution {
public:
    string reverseString(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            res = s[i] + res;
        }
        return res;
    }
};