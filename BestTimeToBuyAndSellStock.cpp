// looked forum
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPrice = INT_MAX;
        for (int p: prices) {
            minPrice = min(minPrice, p);
            maxPro = max(maxPro, p - minPrice);
        }
        return maxPro;
    }
};