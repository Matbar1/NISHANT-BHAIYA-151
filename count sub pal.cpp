int memo[1001][1001][4];
class Solution {
    int mod = 1e9 + 7;
    string s;
    int dp(int first, int last, int ch) {
        if (first > last) return 0;
        if (first == last) return s[first] - 'a' == ch;
        if (memo[first][last][ch] != -1) return memo[first][last][ch];
        int ans = 0;
        if (s[first] == s[last] && s[first] - 'a' == ch) {
            ans = 2;
            for (int i = 0; i < 4; ++i) ans = (ans + dp(first + 1, last - 1, i)) % mod;
        } else {
            ans = (ans + dp(first, last - 1, ch)) % mod;
            ans = (ans + dp(first + 1, last, ch)) % mod;
            ans = (ans - dp(first + 1, last - 1, ch)) % mod;
            if (ans < 0) ans += mod;
        }
        return memo[first][last][ch] = ans;
    }
public:
    int countPalindromicSubsequences(string S) {
        s = S;
        memset(memo, -1, sizeof(memo));
        int ans = 0;
        for (int i = 0; i < 4; ++i) ans = (ans + dp(0, S.size() - 1, i)) % mod;
        return ans;
    }
};