class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int a, b, c, sum, closest;
        bool firstRound = true;
        
        sort(nums.begin(), nums.end());
        for (a = 0; a < n; a++) {
            if (a > 0 && nums[a-1] == nums[a]) continue;
            b = a + 1;
            c = n - 1;
            while (b < c) {
                sum = nums[a] + nums[b] + nums[c];
                if (firstRound) {
                    closest = sum;
                    firstRound = false;
                } else if (abs(target-closest) > abs(target-sum)) {
                    closest = sum;
                }
                if (sum == target) {
                    return sum;
                } else if (sum > target) {
                    c--;
                    while (nums[c] == nums[c+1] && b < c) c--;
                } else {
                    b++;
                    while (nums[b-1] == nums[b] && b < c) b++;
                }
            }
        }
        return closest;
    }
};