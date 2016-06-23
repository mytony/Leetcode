class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)   return true;
        int index = 0;
        int stepsLeft = nums[index];
        while (stepsLeft) {
            index++;
            stepsLeft--;
            if (nums[index] > stepsLeft) {
                stepsLeft = nums[index];
            }
            if (index >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};