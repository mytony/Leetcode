// 爛題目，intersection怎麼解讀成common elements
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> ht (nums1.begin(), nums1.end());
        for (auto num: nums2) {
            if (ht.find(num) != ht.end()) {
                res.push_back(num);
                ht.erase(num);
            }
        }
        return res;
    }
};