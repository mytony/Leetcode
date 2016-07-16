class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        return max(robRow(vector<int>(nums.begin(), nums.end()-1)), 
                   robRow(vector<int>(nums.begin()+1, nums.end())));
    }
private:
    int robRow(vector<int> nums) { // 參數改成reference會出錯
        // two more spaces is for base case
        vector<int> M(nums.size() + 2, 0);
        for (int i = 2; i < M.size(); i++) {
            M[i] = max(nums[i-2] + M[i-2], M[i-1]);
        }
        return M[M.size() - 1];
    }
};