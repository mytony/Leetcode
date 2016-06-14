class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        vector<bool> pick (nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, pick, cur, res);
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<bool>& pick, 
                vector<int>& cur, vector<vector<int>>& res) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        
        int pre;
        bool first = true;
        for (int i = 0; i < nums.size(); i++) {
            // element has already in permutation
            if (pick[i]) continue;
            // this duplicate check is based on sorting
            if (!first && nums[i] == pre) continue;
            
            cur.push_back(nums[i]);
            pick[i] = true;
            
            backtrack(nums, pick, cur, res);
            
            cur.pop_back();
            pick[i] = false;
            
            pre = nums[i];
            if (first)  first = false;
        }
    }
};