// looked internet
// http://bookshadow.com/weblog/2015/11/24/leetcode-best-time-to-buy-and-sell-stock-with-cooldown/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        
        vector<int> sell(n);
        vector<int> buy (n);
        sell[0] = 0;
        buy[0] = -prices[0];
        
        for (int i = 1; i < n; i++) {
            sell[i] = max(buy[i-1] + prices[i], sell[i-1] + prices[i] - prices[i-1]);
            if (i > 1) {
                buy[i] = max(sell[i-2] - prices[i], buy[i-1] + prices[i-1] - prices[i]);
            } else {
                buy[i] = buy[i-1] + prices[i-1] - prices[i];
            }
        }
        
        return *std::max_element(sell.begin(), sell.end());
    }
};