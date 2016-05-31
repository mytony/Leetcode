// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return binarySearch(1, n);
    }
    
    int binarySearch(int start, int end) {
        int mid = start + (end - start) / 2;
        
        if (start == end) {
            return start;
        }
        
        if (isBadVersion(mid)) {
            // search earlier
            return binarySearch(start, mid);
        } else {
            return binarySearch(mid + 1, end);
        }
    }
};

/* reference: use iteration
public int firstBadVersion(int n) {
    int start = 1, end = n;
    while (start < end) {
        int mid = start + (end-start) / 2;
        if (!isBadVersion(mid)) start = mid + 1;
        else end = mid;            
    }        
    return start;
}
*/