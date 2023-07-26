class Solution {
public:
    int maxProfit(vector<int>& prices) {
          int n = prices.size();
        if (n <= 1)
            return 0;

        std::vector<int> buy(n, 0);
        std::vector<int> sell(n, 0);
        std::vector<int> cooldown(n, 0);

        buy[0] = -prices[0];
        sell[0] = 0;
        cooldown[0] = 0;

        for (int i = 1; i < n; ++i) {
            buy[i] = std::max(buy[i - 1], cooldown[i - 1] - prices[i]);
            sell[i] = std::max(sell[i - 1], buy[i - 1] + prices[i]);
            cooldown[i] = std::max(cooldown[i - 1], sell[i - 1]);
        }

        return std::max(sell[n - 1], cooldown[n - 1]);
    }
};
        
    