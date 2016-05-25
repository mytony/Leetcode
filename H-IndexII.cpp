class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int lo = 0, hi = len - 1, mi;
        
        if (len == 0) return 0;
        while (lo < hi) {
            mi = lo + (hi - lo) / 2;
            if (citations[mi] < len - mi) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        if (citations[lo] < len - lo) {
            return len - lo - 1;
        } else {
            return len - lo;
        }
    }
};