// User function template for C++


  
        // Your code goes her
vector<vector<int>> visited(5, vector<int> (5,0));
vector<string> result;

class Solution{
    public:
    void path(vector<vector<int>> &m, int x, int y, string dir, int n) {
        if (x == n - 1 and y == n - 1) {
            result.push_back(dir);
            return;
        }
    
        if (m[x][y] == 0 or visited[x][y] == 1) return;
    
        // DFS
        visited[x][y] = 1;
        if (x > 0) path(m, x - 1, y, dir + 'U', n);
        if (y > 0) path(m, x, y - 1, dir + 'L', n);
        if (x < n - 1) path(m, x + 1, y, dir + 'D', n);
        if (y < n - 1) path(m, x, y + 1, dir + 'R', n);
        visited[x][y] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                visited[i][j] = false;
            }
        }
        result.clear();
    
        if (m[0][0] == 0 || m[n - 1][n - 1] == 0) return result;
    
        path(m, 0, 0, "", n);
    
        sort(result.begin(), result.end());
        return result;
    }
};

    