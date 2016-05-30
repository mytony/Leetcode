class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int assigned = 0, nonzero = 0;
        int n = nums.size();
        
        // pick every non-zero element, fill from the first element
        
        //// A little bit more complicate ////
        // for (; assigned < n; assigned++) {
        //     while (nonzero < n && nums[nonzero] == 0)  nonzero++;
        //     if (nonzero == n) break;
        //     nums[assigned] = nums[nonzero++];
        // }
        
        //// Opposite thinking, easier way ////
        for (int num : nums) {
            if (num != 0)
                nums[assigned++] = num;
        }
        
        // fills zero for the rest
        while (assigned < n)
            nums[assigned++] = 0;
    }
};