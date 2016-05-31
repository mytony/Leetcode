class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 1;
        if (nums.size() == 0) return 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[pos-1]) {
                nums[pos++] = nums[i];
            }
        }
        return pos;
    }
};