class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        // num, times
        unordered_map<int, int> hm;
        
        // build hash map by nums1
        for (auto num: nums1) {
            hm[num]++;
        }
        
        for (auto num: nums2) {
            if (hm.find(num) != hm.end()) {
                res.push_back(num);
                hm[num]--;
                if (hm[num] == 0) {
                    hm.erase(num);
                }
            }
        }
        return res;
    }
};