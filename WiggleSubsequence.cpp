// 這題的subsequence不是指連續，而是刪去某些元素，其他維持順序
// Forum greedy solution is much more concise
/* https://discuss.leetcode.com/topic/51893/two-solutions-one-is-dp-the-other-is-greedy-8-lines/2
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size=nums.size(), f=1, d=1;
        for(int i=1; i<size; ++i){
                 if(nums[i]>nums[i-1]) f=d+1;
            else if(nums[i]<nums[i-1]) d=f+1;
        }
        return min(size, max(f, d));
    }
};
*/
class Solution {
public:
    // Do it greedy
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        
        int len = 1;
        int maxLen = 0;
        bool ascend;
        bool newSeq = true;
        
        for (int i = 1; i < n; i++) {
            if (nums[i-1] == nums[i]) {
                // maxLen = max(maxLen, len);
                // len = 1;
                // newSeq = true;
                continue;
            }
            if (newSeq) {
                newSeq = false;
                ascend = (nums[i-1] < nums[i]) ? true : false;
                len++;
            }
            
            if (ascend ^ nums[i-1] < nums[i]) {
                ascend = !ascend;
                len++;
            }
        }
        maxLen = max(maxLen, len);
        
        return maxLen;
    }
};