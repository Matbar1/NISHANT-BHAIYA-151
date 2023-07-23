class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    int maxHeight(int height[],int width[],int length[],int n)
    {
          int dp[10001];
    	vector<pair<pair<int,int>,int> > v;
    	memset(dp,0,sizeof dp);
    	v.clear();
    	for(int i=0;i<n;i++)
    	{
    		int a,b,c;
    		a=height[i];
    		b = width[i];
    		c=length[i];
    		v.push_back(make_pair(make_pair(a,b),c));
    		v.push_back(make_pair(make_pair(b,a),c));
    		v.push_back(make_pair(make_pair(a,c),b));
    		v.push_back(make_pair(make_pair(c,a),b));
    		v.push_back(make_pair(make_pair(b,c),a));
    		v.push_back(make_pair(make_pair(c,b),a));
    		
    		
    		sort(v.begin(),v.end());
    	}
    	
    	
    	sort(v.begin(),v.end());
    
    	
    	for(int i=0;i<v.size();i++)
    	{
    		dp[i]=v[i].second;
    		for(int j=0;j<i;j++)
    		{
    			if(v[i].first.first>v[j].first.first and v[i].first.second>v[j].first.second)
    			{
    				dp[i]=max(dp[i],dp[j]+v[i].second);
    			}
    		}
    	}
     
    	int m=INT_MIN;
    	for(int i=0;i<v.size();i++)
    		m = max(dp[i],m);
     
    	return m;
    
    }
};