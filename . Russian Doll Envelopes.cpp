class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]; });
        vector<int> dp;
        for (auto &v : A) {
            auto it = lower_bound(begin(dp), end(dp), v[1]);
            if (it == end(dp)) dp.push_back(v[1]);
            else *it = v[1];
        }
        return dp.size();
    }
};