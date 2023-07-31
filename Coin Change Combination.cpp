#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int amt;
    cin >> amt;

    vector<int> dp(amt + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int i = 1; i < dp.size(); i++) {
            if (i >= coin) {
                dp[i] += dp[i - coin];
            }
        }
    }

    cout << dp[amt] << endl;

    return 0;
}