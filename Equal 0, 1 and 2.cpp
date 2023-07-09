class Solution {
  public:
    long long getSubstringWithEqual012(string str)
    {
        long long n = str.length();
    
        // map to store, how many times a difference
        // pair has occurred previously
        unordered_map<string, long long> mp;
        mp["0*0"] = 1;
    
        //  zc (Count of zeroes), oc(Count of 1s)
        //  and tc(count of twos)
        //  In starting all counts are zero
        long long zc = 0, oc = 0, tc = 0;
    
        //  looping llo string
        long long res = 0;  // Initialize result
        for (int i = 0; i < n; ++i)
        {
            // incresing the count of current character
            if (str[i] == '0') zc++;
            else if (str[i] == '1') oc++;
            else tc++;  // Assuming that string doesn't contain
                        // other characters
    
            // making pair of differences (z[i] - o[i],
            // z[i] - t[i])
            string key = to_string(zc - oc) + "*" + to_string(zc - tc);
    
            // Count of previous occurrences of above pair
            // indicates that the subarrays forming from
            // every previous occurrence to this occurrence
            // is a subarray with equal number of 0's, 1's
            // and 2's
            res = res + mp[key];
    
            // increasing the count of current difference
            // pair by 1
            mp[key]++;
        }
    
        return res;
    }
};