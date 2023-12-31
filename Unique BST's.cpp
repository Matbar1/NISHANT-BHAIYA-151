class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    int numTrees(int n) 
    {
        //dp[] to store the number of unique BST with key i.
        int dp[n+1];
        
        //base cases
        dp[0]=1;
        dp[1]=1;
        int mod = 1000000007;
        
        //filling the dp[] table in top-down approach.
        for(int i=2;i<=n;i++)
        {
            dp[i]=0;
            for(int j=1;j<=i;j++)
            {
                //if we take j as root, then [1â€¦.j-1] numbers will fall in the
                //left subtree and [j+1â€¦.i] numbers will fall in the right
                //subtree. So, we add dp[j-1]*dp[i-j] to dp[i].
                dp[i] = (dp[i]+ (1LL*dp[j-1]*dp[i-j])%mod)%mod;
            }
        }
        
        //returning the answer.
        return dp[n];

    }
};