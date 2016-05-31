class Solution {
public:
    // search lower and higher bound separately
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        
        binarySearch(nums, 0, nums.size()-1, target, res, true);
        // if lower-bound has been found
        if (res[0] >= 0)
            binarySearch(nums, res[0], nums.size()-1, target, res, false);
        return res;
    }
    
    // the boolean flag controls whether search lower or higher bound
    // The flag prevents from searching the bound again
    // when we already have in mind
    void binarySearch(vector<int>& nums, int start, int end, int target, vector<int>& res, bool left) {
        if (start > end) return;
        if (start == end && nums[start] != target) return;
        
        int mid = start + (end - start) / 2;

        if (nums[mid] < target) {
            binarySearch(nums, mid+1, end, target, res, left);
        } else if (nums[mid] > target) {
            binarySearch(nums, start, mid-1, target, res, left);
        } else { // number = target
            if (left) {
                if (mid == 0 || nums[mid-1] != target) { // found lower-bound
                    res[0] = mid;
                } else {
                    binarySearch(nums, start, mid-1, target, res, left);
                }
            } else {
                if (mid == nums.size()-1 || nums[mid+1] != target) { // found higher-bound
                    res[1] = mid;
                } else {
                    binarySearch(nums, mid+1, end, target, res, left);
                }
            }
        }
    }
};