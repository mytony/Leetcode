class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for(int k = 0; k < s.length(); k++){
            ans = 26 * ans + (s[k] - 'A' + 1);
        }
        return ans;
    }
};
