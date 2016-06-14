class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // k means the last k elements will be in front,
        // which means other elements will be behind of 
        // the last k elements. So my idea is push first 
        // elements in the back and delete it for n-k times.
        int n = nums.size();
        if (k == 0) return;
        if (k > n) k %= n;
        for (int i = 0; i < n - k; i++) {
            nums.push_back(nums[i]);
            nums.erase(nums.begin());
        }
    }
};