class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.length() + 1, vector<int>(p.length() + 1, -1));
        return dp(0, 0, s, p, memo);
    }

    bool dp(int i, int j, const string& s, const string& p, vector<vector<int>>& memo) {
        if (memo[i][j] != -1) {
            return memo[i][j] == 1;
        }

        bool ans;
        if (j == p.length()) {
            ans = (i == s.length());
        } else {
            bool first_match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

            if (j + 1 < p.length() && p[j + 1] == '*') {
                ans = (dp(i, j + 2, s, p, memo)) || (first_match && dp(i + 1, j, s, p, memo));
            } else {
                ans = first_match && dp(i + 1, j + 1, s, p, memo);
            }
        }

        memo[i][j] = ans ? 1 : 0;
        return ans;
    }
};
