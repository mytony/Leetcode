class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n - 1, mid;
        if (n == 0) return -1;
        int f = nums[0];
        
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            int num = nums[mid];
            
            // I come up with below statements by
            // writing on paper all conditions
            // then simplify it
            if (num < target) {
                if (num < f && target >= f) hi = mid - 1;
                else    lo = mid + 1;
            } else if (num > target) {
                if (num >= f && target < f) lo = mid + 1;
                else    hi = mid - 1;
            } else {
                return mid;
            }
        }
        return nums[lo] == target ? lo : -1;
    }
};