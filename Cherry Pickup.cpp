class Solution {
public:
    int cherryPickup(vector<vector<int>>& A) {
        int N = A.size(), memo[51][51][51] = {}; // INT_MIN = non-reachable, -1 = unvisited
        memset(memo, -1, sizeof(memo));
        function<int(int, int, int)> dp = [&](int r1, int c1, int c2) {
            int r2 = r1 + c1 - c2;
            if (r1 == N || r2 == N || c1 == N || c2 == N || A[r1][c1] == -1 || A[r2][c2] == -1) return INT_MIN; // If out-of-bound or non-reachable, return -Infinity
            if (r1 == N - 1 && c1 == N - 1) return A[r1][c1];
            if (memo[r1][c1][c2] != -1) return memo[r1][c1][c2];
            int ans = A[r1][c1];
            if (c1 != c2) ans += A[r2][c2];
            ans += max({ dp(r1, c1 + 1, c2 + 1), dp(r1, c1 + 1, c2), dp(r1 + 1, c1, c2 + 1), dp(r1 + 1, c1, c2) });
            return memo[r1][c1][c2] = ans;
        };
        return max(0, dp(0, 0, 0));
    }
};