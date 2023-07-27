class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
         int m = text1.size();
        int n = text2.size();
        
        // Initialize the 2D DP array with zeros
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    // If the characters match, add 1 to the previous diagonal value
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // If the characters don't match, take the maximum of the previous row or previous column
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[m][n];
    }
};
        
    class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
         int m = text1.size();
        int n = text2.size();
        
        // Initialize the 2D DP array with zeros
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    // If the characters match, add 1 to the previous diagonal value
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // If the characters don't match, take the maximum of the previous row or previous column
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[m][n];
    }
};
        
    