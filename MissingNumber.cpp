class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // []    missing 0
        // [0]   missing 1
        // [0,1] missing 2
        // [1]   missing 0
        if (nums.empty()) {
            return 0;
        }
        bool existZero = false;
        int sum = 0, max = 0, total = 0;
        
        // get sum and max of the vector
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (nums[i] > max) {
                max = nums[i];
            }
            if (nums[i] == 0) {
                existZero = true;
            }
        }
        // supposed complete sum 0~max
        for (int i = 0; i <= max; i++) {
            total += i;
        }
        
        return (total == sum) ? (existZero ? max + 1 : 0) : (total - sum);
    }
};
