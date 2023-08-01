class Solution {
public:
   int orangesRotting(std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    std::queue<std::pair<int, int>> rottenQueue;
    int freshCount = 0;

    // Find initial rotten oranges and count fresh oranges
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                rottenQueue.push({i, j});
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    int minutes = 0;
    std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!rottenQueue.empty() && freshCount > 0) {
        int size = rottenQueue.size();
        for (int i = 0; i < size; i++) {
            int x = rottenQueue.front().first;
            int y = rottenQueue.front().second;
            rottenQueue.pop();

            for (const auto& direction : directions) {
                int newX = x + direction.first;
                int newY = y + direction.second;

                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;
                    freshCount--;
                    rottenQueue.push({newX, newY});
                }
            }
        }

        if (!rottenQueue.empty()) {
            minutes++;
        }
    }

    return (freshCount == 0) ? minutes : -1;
}
};