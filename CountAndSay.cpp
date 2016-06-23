class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        // do the transformation n times starting from "1"
        for (int i = 1; i < n; i++) {
            // append the new sequence and delete the old one
            int len = res.size();
            char c = res[0];
            int count = 1;
            for (int j = 1; j < len; j++) {
                if (res[j] == c) {
                    count++;
                } else {
                    // print the group so far
                    res += to_string(count) + string(1, c);
                    count = 1;
                    c = res[j];
                }
            }
            // print the last group
            res += to_string(count) + string(1, c);
            // delete the old sequence
            res.erase(0, len);
        }
        return res;
    }
};