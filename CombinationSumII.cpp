class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        // backtrack(candidates, target, 0);
        comb(candidates, target, 0);
        return res;
    }
    
    // Don't know how to avoid duplicate answer for this coding style
    void backtrack(vector<int>& cands, int target, int pos) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (pos == cands.size() || target < 0) return;
        
        // not choose
        backtrack(cands, target, pos + 1);
        // choose
        cur.push_back(cands[pos]);
        backtrack(cands, target - cands[pos], pos + 1);
        cur.pop_back();
    }
    
    // Tina's 
    void comb(vector<int>& cands, int target, int pos) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = pos; i < cands.size(); i++) {
            if (cands[i] > target)  break;
            // IMPORTANT: i > 'pos'
            if (i > pos && cands[i] == cands[i-1])  continue;
            cur.push_back(cands[i]);
            comb(cands, target - cands[i], i + 1);
            cur.pop_back();
        }
    }
};