class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res (num + 1);
        res[0] = 0;
        int loops = 1;
        for(int i = 1, j = 0; i <= num; i++, j++) {
            if (j == loops) {
                loops <<= 1;
                j = 0;
            }
            res[i] = res[i-loops] + 1;
        }
        return res;
    }
};