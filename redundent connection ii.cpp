class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& E) {
        int N = E.size(), terminal = -1;
        vector<vector<pair<int, int>>> G(N);
        vector<vector<pair<int, int>>> R(N);
        vector<bool> onCycle(N, true);
        vector<int> indegree(N), outdegree(N);
        for (int i = 0; i < N; ++i) {
            int u = E[i][0] - 1, v = E[i][1] - 1;
            G[u].push_back({v,i});
            R[v].push_back({u,i});
            if (++indegree[v] == 2) terminal = v;
            ++outdegree[u];
        }
        auto hasCycle = [&]() { // Topological sort to see if there is any cycle in the graph
            queue<int> q;
            int seen = 0;
            for (int i = 0; i < N; ++i) {
                if (indegree[i] == 0) q.push(i);
            }
            while (q.size()) {
                int u = q.front();
                onCycle[u] = false;
                ++seen;
                q.pop();
                for (auto &[v, i] : G[u]) {
                    if (--indegree[v] == 0) q.push(v);
                }
            }
            return seen < N;
        };
        if (hasCycle()) {
            if (terminal != -1) { // case 1
                int a = R[terminal][0].first, b = R[terminal][1].first;
                if (onCycle[a]) return {a + 1, terminal + 1};
                return {b + 1, terminal + 1};
            }
            queue<int> q; // case 3
            for (int i = 0; i < N; ++i) {
                if (outdegree[i] == 0) q.push(i);
            }
            while (q.size()) {
                int u = q.front();
                q.pop();
                onCycle[u] = false; // Topological Sort on the reversed graph to remove nodes that are not on the cycle.
                for (auto &[v, i] : R[u]) {
                    if (--outdegree[v] == 0) q.push(v);
                }
            }
            int ans = -1;
            for (int i = 0; i < N; ++i) {
                if (!onCycle[i]) continue;
                for (auto &[v, j] : R[i]) {
                    ans = max(ans, j); // Find the greatest edge index on the cycle
                }
            }
            return E[ans];
        }
        return {R[terminal][1].first + 1, terminal + 1}; // case 2
    }
};