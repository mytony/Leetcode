class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        backtrack(s, 0, 1, "", 0, res);
        return res;
    }
    
    void backtrack(string s, int pos, int len, string cur, int part, vector<string>& res) {
        if (part == 4 && pos == s.size()) {
            res.push_back(cur);
            return;
        }
        // There are digits left and no more space for IP address
        if (part == 4)  return;
        if (pos + len > s.size()) return;
        
        // special case, there is not 0x or 0xx
        if (s.substr(pos, len) == "0") {
            string tmp = cur;
            tmp += "0";
            if (part < 3) tmp += ".";
            backtrack(s, pos+len, 1, tmp, part+1, res);
            return;
        }
        // form a number
        if (stoi(s.substr(pos, len)) < 256) {
            string tmp = cur;
            tmp += s.substr(pos, len);
            if (part < 3) tmp += ".";
            backtrack(s, pos+len, 1, tmp, part+1, res);
        }
        // keep adding a digit
        if (len < 3)
            backtrack(s, pos, len+1, cur, part, res);
    }
};