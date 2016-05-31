class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // key point is 'end = nums.size()'
        int start = 0, end = nums.size();
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};