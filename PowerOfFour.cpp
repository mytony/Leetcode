class Solution {
public:
    // Check if there is only a bit 1 and at right position
    bool isPowerOfFour(int num) {
        if (num < 0) return false;
        int count = 0;
        // Bit 31 is signed bit
        for (int i = 0; i < 31; i++, num >>= 1) {
            if (num & 1) {
                if (count > 0 || i % 2 != 0) {
                    return false;
                }
                count++;
            }
        }
        return count == 1 ? true : false;
    }
};