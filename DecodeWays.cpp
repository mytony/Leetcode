class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0)  return 0;
        if (s[0] == '0')    return 0;
        int pp = 0, pre = 0; // number of choices of second previous and previous state
        int now = 1;
        for (int i = 0; i < s.size(); i++) {
            pp = pre;
            pre = now;
            now = 0;
            if (s[i] != '0') {
                now += pre;
            }
            if (i == 0 || s[i-1] == '0' || s[i-1] > '2' || 
                (s[i-1] == '2' && s[i] > '6')) {
                continue;
            }
            now += pp;
        }
        return now;
    }
};