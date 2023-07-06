class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
        unordered_map<int, int> m{ {0,1} };
        int sum = 0, ans = 0;
        for (int n : A) {
            sum += n;
            if (sum >= 0) sum %= k;
            else sum = (k - (-sum % k)) % k;
            ans += m[sum];
            m[sum]++;
        }
        return ans;
    }
};