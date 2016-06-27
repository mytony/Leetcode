class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;
        // when all elements in nums2 have cleared, the result is done
        while (j >= 0) {
            if (i >= 0) {
                if (nums1[i] < nums2[j]) {
                    nums1[k--] = nums2[j--];
                } else {
                    nums1[k--] = nums1[i--];
                }
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
    }
};