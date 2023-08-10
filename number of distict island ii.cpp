    int numDistinctIslands(std::vector<std::vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int rows = grid.size();
        int cols = grid[0].size();
        std::unordered_set<std::string> islands; // To store unique island shapes
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    std::string islandShape;
                    dfs(grid, i, j, i, j, islandShape);
                    islands.insert(islandShape);
                }
            }
        }
        
        return islands.size();
    }
    
private:
    void dfs(std::vector<std::vector<int>>& grid, int i, int j, int base_i, int base_j, std::string& islandShape) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) {
            return;
        }
        
        grid[i][j] = 0; // Mark as visited
        
        int delta_i = i - base_i;
        int delta_j = j - base_j;
        
        islandShape += std::to_string(delta_i) + "_" + std::to_string(delta_j) + "_";
        
        dfs(grid, i + 1, j, base_i, base_j, islandShape); // Down
        dfs(grid, i - 1, j, base_i, base_j, islandShape); // Up
        dfs(grid, i, j + 1, base_i, base_j, islandShape); // Right
        dfs(grid, i, j - 1, base_i, base_j, islandShape); // Left
    }
};