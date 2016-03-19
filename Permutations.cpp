class Solution {
public:
// does order between permutations matter? No
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        cur.reserve(nums.size()); // speed up
        step(nums, cur, result);
        return result;
    }
    
    void step(vector<int> &options, vector<int> &cur, vector<vector<int>> &res) {
        // stop case
        if (options.empty()) {
            res.push_back(cur);
            return;
        }
        
        for (int i = 0; i < options.size(); i++) {
            vector<int> copy (options);
            cur.push_back(options[i]);
            copy.erase(copy.begin() + i);
            step(copy, cur, res);
            cur.pop_back();
        }
    }
};
