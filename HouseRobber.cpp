class Solution {
public:
    int rob(vector<int>& nums) {
        // two more spaces is for base case
        vector<int> M(nums.size() + 2, 0);
        for (int i = 2; i < M.size(); i++) {
            M[i] = max(nums[i-2] + M[i-2], M[i-1]);
        }
        return M[M.size() - 1];
    }
};