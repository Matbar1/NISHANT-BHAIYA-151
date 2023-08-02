class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    
    vector<vector<int>> distance(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    // Enqueue all cells with 0 value and set their distance to 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                q.push({i, j});
                distance[i][j] = 0;
            }
        }
    }

    // Define the four possible directions: up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Perform BFS to find the distance of nearest 0 for each cell
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        
        int row = curr.first;
        int col = curr.second;
        
        for (const auto& dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && distance[newRow][newCol] == -1) {
                distance[newRow][newCol] = distance[row][col] + 1;
                q.push({newRow, newCol});
            }
        }
    }

    return distance;
    }
};