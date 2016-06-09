class Solution {
public:
// does order between permutations matter? No
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        vector<bool> pick (nums.size(), false);
        
        cur.reserve(nums.size()); // speed up
        step(nums, cur, result, pick);
        return result;
    }
    
    void step(vector<int> &options, vector<int> &cur, vector<vector<int>> &res, vector<bool>& pick) {
        // stop case
        if (cur.size() == options.size()) {
            res.push_back(cur);
            return;
        }
        
        for (int i = 0; i < options.size(); i++) {
            if (pick[i]) continue;
            cur.push_back(options[i]);
            pick[i] = true;
            step(options, cur, res, pick);
            cur.pop_back();
            pick[i] = false;
        }
    }
};