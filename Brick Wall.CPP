class Solution {
public:
    int leastBricks(vector<vector<int>>& A) {
        int mx = 0;
        unordered_map<int, int> m;
        for (auto &v : A) {
            for (int i = 0, x = 0; i < v.size() - 1; ++i) {
                mx = max(mx, ++m[x += v[i]]);
            }
        }
        return A.size() - mx;
    }
};