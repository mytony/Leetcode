class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j, min, tmp;
        
        // search from back, if there's a pair is ascending order e.g. (2,3)
        for (i = nums.size() - 1; i > 0; i--) {
            if (nums[i-1] < nums[i]) {
                break;
            }
        }
        
        // whole vector is in descending order
        if (i == 0) {
            return sort(nums.begin(), nums.end());
        }
        
        // search min element which is bigger than [i-1] from i to replace [i-1]
        min = i;
        for (j = i + 1; j < nums.size(); j++) {
            if (nums[min] > nums[j] && nums[j] > nums[i-1]) {
                min = j;
            }
        }
        
        // swap nums[i-1] and nums[min]
        tmp = nums[i-1];
        nums[i-1] = nums[min];
        nums[min] = tmp;
        
        // sort all elements from i
        sort(nums.begin() + i, nums.end());
    }
};
