// Similart to Combination Sum II
class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return res;
    }
    
    void backtrack(vector<int>& nums, int pos) {
        // every combination is an answer, just push
        res.push_back(cur);
        
        for (int i = pos; i < nums.size(); i++) {
            if (i > pos && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            backtrack(nums, i+1);
            cur.pop_back();
        }
    }
};