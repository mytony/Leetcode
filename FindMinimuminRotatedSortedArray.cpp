class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            // The nums[mid] == nums[0] could only happen
            // when the windows size becomes two.
            // If we change 'lo' when nums[mid] >= nums[0], 
            // it will be wrong when window is size of two
            if (nums[mid] > nums[0]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return nums[lo];
    }
};