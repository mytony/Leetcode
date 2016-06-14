// https://leetcode.com/discuss/46104/simple-java-solution-in-o-n-without-extra-space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1;
        vector<int> res (nums.size());
        res[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            left *= nums[i-1];
            res[i] = left;
        }
        
        int right = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            res[i] *= right;
            right *= nums[i];
        }
        
        return res;
    }
};