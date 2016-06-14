class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size()-1 );
    }
    
    int binarySearch(vector<int>& nums, int start, int end) {
        int mid = start + (end - start) / 2;
        if (mid+1 < nums.size() && nums[mid] < nums[mid+1])
            return binarySearch(nums, mid+1, end);
        if (mid > 0 && nums[mid-1] > nums[mid])
            return binarySearch(nums, start, mid-1);
        return mid;
    }
};