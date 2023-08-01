class Solution {
public:
   bool isBipartite(vector<vector<int>>& G) {
        int N = G.size();
        vector<int> id(N); // 0 unseen, 1 and -1 are different colors
        function<bool(int, int)> dfs = [&](int u, int color) {
            if (id[u]) return id[u] == color;
            id[u] = color;
            for (int v : G[u]) {
                if (!dfs(v, -color)) return false;
            }
            return true;
        };
        for (int i = 0; i < N; ++i) {
            if (!id[i] && !dfs(i, 1)) return false;
        }
        return true;
    }
};