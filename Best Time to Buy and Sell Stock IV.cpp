class Solution {
public:
    int maxProfit(int k, std::vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) return 0;

    // If k is large enough to cover all possible transactions, we can use the optimized solution
    if (k >= n / 2) {
        int maxProfit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1])
                maxProfit += prices[i] - prices[i - 1];
        }
        return maxProfit;
    }

    std::vector<int> buy(k + 1, INT_MIN);
    std::vector<int> sell(k + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            buy[j] = std::max(buy[j], sell[j - 1] - prices[i]);
            sell[j] = std::max(sell[j], buy[j] + prices[i]);
        }
    }

    return sell[k];
}
};