// looked forum
class Solution {
public:
    // bit manipulation
    // check if each bit is major, then combines them into number
    int majorityElement(vector<int>& nums) {
        int major = 0;
        int count;
        int n = nums.size();
        for (int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
            count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] & mask) count++;
            }
            if (count > n / 2)  major |= mask;
        }
        return major;
    }
};