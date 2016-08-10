// Forum solution
// Python concise one: https://discuss.leetcode.com/topic/53303/time-o-n-8-line-python-solution-based-on-bucket
// 
class Solution {
public:
    // goal: abs(nums[i]-nums[j]) <= t && abs(i-j) <= k
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // if (k == 0) return false;
        unordered_map<int, int> buckets;
        int bucketNum, offset;
        for (int i = 0; i < nums.size(); i++) {
            if (t == 0) {
                bucketNum = nums[i];
                offset = 0;
            } else {
                bucketNum = nums[i] / t;
                offset = 1;
            }
            
            for (int b = bucketNum - 1; b < bucketNum + 2; b++) {
                if (buckets.find(b) != buckets.end() && abs((long)buckets[b] - (long)nums[i]) <= t) {
                    return true;
                }
            }
            
            buckets[bucketNum] = nums[i];
            
            if (buckets.size() > k) {
                if (t == 0) {
                    buckets.erase(nums[i-k]);
                } else {
                    buckets.erase(nums[i-k] / t);
                }
            }
        }
        return false;
    }
};