class Solution{
	public:
	int TotalWays(int N)
	{
	    long long int mod = 1000000007;
		vector<long long int>f(N+1);
		f[0] = f[1] = 1;
		for(int i = 2; i <= N; i++)
			f[i]  = (f[i-1]%mod + f[i-2]%mod)%mod;
		long long int x = (f[N] + f[N-1])%mod;
		x = x * x;
		x %= mod;
		return int(x);
	    // Code here
	}
};