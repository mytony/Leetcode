class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Since the no extra memory requirement, 
        // use a num of array to store final result
        for (int i = 1; i< nums.size(); i++) {
            nums[0] ^= nums[i];
        }
        return nums[0];
    }
};