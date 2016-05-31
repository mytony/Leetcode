class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int front = 0, end = 0, sum = 0, minlen = nums.size() + 1;
        while (end < nums.size()) {
            sum += nums[end++];
            while (sum >= s) {
                minlen = min(minlen, end - front);
                sum -= nums[front++];
            }
        }
        return minlen == nums.size() + 1 ? 0 : minlen;
    }
};