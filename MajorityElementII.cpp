// looked forum
class Solution {
public:
    // Use voting algorithm, since there are at most 
    // 2 majority elements, we use two variable to track
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, a = 0, b = 1;
        for (int n: nums) {
            if (n == a) {
                cnt1++;
            } else if (n == b) {
                cnt2++;
            } else if (cnt1 == 0) {
                cnt1++;
                a = n;
            } else if (cnt2 == 0) {
                cnt2++;
                b = n;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 = 0; cnt2 = 0;
        for (int n: nums) {
            if (n == a) {
                cnt1++;
            }
            if (n == b) {
                cnt2++;
            }
        }
        
        vector<int> res;
        if (cnt1 > nums.size() / 3)
            res.push_back(a);
        if (cnt2 > nums.size() / 3)
            res.push_back(b);
        return res;
    }
};