class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int a, b, c, d, sum;
        int n = nums.size();
        vector<vector<int>> res;
        
        if (n < 4) return {};
        sort(nums.begin(), nums.end());
        
        // fix a, b, let c, d change
        for (a = 0; a < n; a++) {
            if (a > 0 && nums[a-1] == nums[a]) continue;
            
            for (b = a + 1; b < n; b++) {
                if (b > a + 1 && nums[b-1] == nums[b]) continue;
                c = b + 1;
                d = n - 1;
                
                while (c < d) {
                    sum = nums[a] + nums[b] + nums[c] + nums[d];
                    if (sum == target) {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                        c++;
                        d--;
                        while (nums[c-1] == nums[c] && c < d) c++;
                        while (nums[d] == nums[d+1] && c < d) d--;
                    } else if (sum < target) {
                        c++;
                        while (nums[c-1] == nums[c] && c < d) c++;
                    } else {
                        d--;
                        while (nums[d] == nums[d+1] && c < d) d--;
                    }
                }
            }
        }
        return res;
    }
};