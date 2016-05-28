class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> history;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            if (history.find(*it) == history.end()) {
                history[target - *it] = it - nums.begin();
            } else {
                ans.push_back( history[*it] );
                ans.push_back( it - nums.begin() );
                break;
            }
        }
        return ans;
    }
};