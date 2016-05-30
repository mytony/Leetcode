class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        int a, b, c, sum; // a, b, c are the leftmost, middle, rightmost element
        vector<vector<int>> res;
        
        if (size < 3) return {};
        
        // everytime a is fixed, adjust b and c according to the sum
        // After sorting, we can adjust easily based on the order.
        // b initialized to a+1 and c initialized to n-1 element
        sort(nums.begin(), nums.end());
        for (a = 0; a < size - 2; a++) {
            // special pruning condition
            if (nums[a] > 0) break;
            
            // duplicate searching
            if (a > 0 && nums[a] == nums[a-1]) continue;
            
            b = a + 1;
            c = size - 1;
            while (b < c) {
                sum = nums[a] + nums[b] + nums[c];
                if (sum == 0) {
                    res.push_back({nums[a], nums[b], nums[c]});
                    b++;
                    c--;
                    // avoid duplicate
                    while (nums[b-1] == nums[b] && b < c) b++;
                    while (nums[c] == nums[c+1] && b < c) c--;
                } else if (sum > 0) {
                    c--;
                    // not necessary, the while loop would handle
                    // while (nums[c] == nums[c+1] && b < c) c--;
                } else {
                    b++;
                    // not necessary, the while loop would handle
                    // while (nums[b-1] == nums[b] && b < c) b++;
                }
            }
        }
        return res;
    }
};