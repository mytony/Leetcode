class Solution {
public:
    // Using backtracking
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return res;
    }
    
private:
    vector<vector<int>> res;
    vector<int> cur;
    
    void backtrack(vector<int>& cands, int target, int pos) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (pos == cands.size()) return;
        
        // Below, Tina has different code and logic, looks cleaner
        int times = 0;
        while(cands[pos] * times <= target) {
            cur.insert(cur.end(), times, cands[pos]);
            
            backtrack(cands, target - cands[pos] * times, pos + 1);
            
            for (int i = 0; i < times; i++) cur.pop_back();
            times++;
        }
    }
};