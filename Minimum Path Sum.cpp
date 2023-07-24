class Solution {
public:
   int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    // Create a DP table to store the minimum path sum
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    // Initialize the first row and column
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int j = 1; j < n; j++)
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    
    // Fill in the rest of the DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    
    // Return the minimum path sum
    return dp[m - 1][n - 1];
}
};