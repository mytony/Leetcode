class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int lo = 0, hi = len - 1, mi;

        while (lo <= hi) {
            mi = lo + (hi - lo) / 2;
            if (citations[mi] < len - mi) {
                lo = mi + 1;
            } else {
                hi = mi - 1;
            }
        }
        return len - lo;
    }
};