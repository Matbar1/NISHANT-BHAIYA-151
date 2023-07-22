class Solution {
public:
   int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    
    // Create a vector to store the longest increasing subsequence length for each index
    vector<int> dp(n, 1);
    
    // Iterate through all indices from 1 to n-1
    for (int i = 1; i < n; i++) {
        // Check all previous indices to find the longest increasing subsequence ending at i
        for (int j = 0; j < i; j++) {
            // If the current number is greater than the previous number and can extend the subsequence
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    // Find the maximum length of the longest increasing subsequence
    int maxLen = 1;
    for (int i = 0; i < n; i++) {
        maxLen = max(maxLen, dp[i]);
    }
    
    return maxLen;
}
};