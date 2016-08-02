// https://leetcode.com/discuss/9763/accepted-proper-explaination-does-anyone-have-better-idea
// https://discuss.leetcode.com/topic/43166/java-o-n-easy-to-understand-solution-easily-extended-to-any-times-of-occurance
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        // For every bit, find the set bit of the single number
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (auto num: nums) {
                if (num & (1 << i)) {
                    sum++;
                }
                if (sum == 3) {
                    sum = 0;
                }
            }
            // the i-th bit of single number is set
            if (sum > 0) {
                res |= 1 << i; // set the i-th bit
            }
        }
        return res;
    }
};