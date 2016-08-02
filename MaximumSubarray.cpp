class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        size_t n = nums.size();
        // Forum solution
        vector<int> dp(n);
        dp[0] = nums[0];
        int maxSum = nums[0];
        
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i-1] > 0 ? dp[i-1] + nums[i] : nums[i];
            maxSum = max(maxSum, dp[i]);
        }
        
        return maxSum;
        
        /* 
        // self solution: will cause Memory Limit Exceeded when large vector
        int maxSum = INT_MIN;
        vector<vector<int>> sumRange(n, vector<int>(n));
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    sumRange[i][j] = nums[i];
                } else {
                    sumRange[i][j] = sumRange[i][i] + sumRange[i+1][j];
                }
                
                maxSum = max(maxSum, sumRange[i][j]);
            }
        }
        
        return maxSum;
        */
    }
};