// good picture explanation of each solution
// https://leetcode.com/discuss/46668/recursive-iterative-manipulation-solutions-explanations
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // solutionByRecursion(nums);
        return solutionByBitManipulation(nums);
    }
private:
    // copied from discussion
    // Idea: each element taken or not, 
    //       is exaclty the bits from 0 to 2^N-1
    vector<vector<int>> solutionByBitManipulation(vector<int>& S) {
        sort (S.begin(), S.end());
        int elem_num = S.size();
        int subset_num = pow (2, elem_num);
        vector<vector<int> > subset_set (subset_num, vector<int>());
        for (int i = 0; i < elem_num; i++)
            for (int j = 0; j < subset_num; j++)
                if ((j >> i) & 1)
                    subset_set[j].push_back (S[i]);
        return subset_set;
    }
    
    vector<vector<int>> solutionByIteration(vector<int>& nums) {
        // in the link at the top
    }
    
    vector<vector<int>> solutionByRecursion(vector<int>& nums) {
        vector<int> curAns;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        // each loop finds different size of subset
        for (int i = 0; i <= nums.size(); i++) {
            findSubset(i, 0, nums, curAns, res);
        }
        return res;
    }
    
    void findSubset(int size, int pos, vector<int>& nums, vector<int>& curAns, vector<vector<int>>& res) {
        // stop case
        if (curAns.size() == size) {
            res.push_back(curAns);
            return;
        }
        
        for (int i = pos; i < nums.size(); i++) {
            curAns.push_back(nums[i]);
            findSubset(size, i+1, nums, curAns, res);
            curAns.pop_back();
        }
    }
};