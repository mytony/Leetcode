// forum
// https://discuss.leetcode.com/topic/6491/share-my-c-solution-maybe-is-the-simplest-solution
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int frontProduct = 1;
        int backProduct = 1;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            frontProduct *= nums[i];
            backProduct *= nums[n-1-i];
            ans = max(ans, max(frontProduct, backProduct));
            frontProduct = frontProduct == 0 ? 1 : frontProduct;
            backProduct = backProduct == 0 ? 1 : backProduct;
        }
        return ans;
    }
};