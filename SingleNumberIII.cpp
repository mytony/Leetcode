// looked forum
// https://leetcode.com/discuss/52351/accepted-java-space-easy-solution-with-detail-explanations
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // XOR every elements
        int num1 = 0;
        for (int n: nums) {
            num1 ^= n;
        }
        // Find a set bit
        int i;
        for (i = 0; i < 32; i++) {
            if (num1 & (1 << i)) break;
        }
        // Separate into two groups by the set bit just found
        vector<int> res = {0, 0};
        for (int n: nums) {
            if (n & (1 << i)) {
                res[0] ^= n;
            }
        }
        res[1] = res[0] ^ num1;
        return res;
    }
};