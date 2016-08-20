// https://discuss.leetcode.com/topic/53979/straight-forward-c-solution
class Solution {
private:
    vector<int> nums_;
public:
    Solution(vector<int> nums) {
        nums_.assign(nums.begin(), nums.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result(nums_);
        for (int i = 0; i < result.size(); i++) {
            int pos = rand() % (result.size() - i);
            swap(result[i+pos], result[i]);
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */