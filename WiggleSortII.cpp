// O(nlogn): https://discuss.leetcode.com/topic/32882/short-simple-c
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        for (int i = nums.size() - 1, j = 0, k = i / 2 + 1; i >= 0; i--) {
            nums[i] = sorted[i & 1 ? k++ : j++];
        }
        
        // My wrong idea is taking turn to put min and max of integers
        // But it got a wrong answer
        // Input: [1,3,2,2,3,1]
        // Output would be [1,3,1,3,2,2]. The problem is 2 and 2
        // for (int i = 0, j = 0, k = n-1; i < n; i++) {
        //     nums[i] = sorted[i & 1 ? k-- : j++];
        // }
    }
};