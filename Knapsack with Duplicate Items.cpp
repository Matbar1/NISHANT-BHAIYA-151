class Solution{
public:
     int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> dp(W+1 , 0);
		int ans =0;

		for(int i=0; i<W+1; i++)
			for (int j=0; j<N; j++)
				if(wt[j]<= i)
					dp[i] = max(dp[i], dp[i - wt[j]] + val[j]) ;
		return dp[W];
    }
};