class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return n;
        }
        int num = nums[0];
        int pos = 1;
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (count < 2 && num == nums[i]) {
                nums[pos++] = nums[i];
                count++;
            } else if (num != nums[i]){
                nums[pos++] = nums[i];
                num = nums[i];
                count = 1;
            }
        }
        return pos;
    }
};