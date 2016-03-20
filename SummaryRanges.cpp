class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int head = 0;
        vector<string> res;
        
        for (int i = 0; i < nums.size(); i++) {
            // foresee the next element
            if (i + 1 == nums.size() || nums[i] + 1 != nums[i+1]) {
                if (head == i) {
                    res.push_back(to_string(nums[i]));
                } else {
                    res.push_back(to_string(nums[head]) + "->" + to_string(nums[i]));
                }
                head = i + 1;
            }
        }
        
        return res;
    }
};