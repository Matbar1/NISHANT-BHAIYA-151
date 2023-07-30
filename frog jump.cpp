class Solution {
public:
    bool canCross(std::vector<int>& stones) {
        int n = stones.size();
        // Create a map to store possible jumps from each stone
        std::unordered_map<int, std::unordered_set<int>> jumpMap;

        // Fill the map with possible jumps for each stone
        for (int stone : stones) {
            jumpMap[stone] = std::unordered_set<int>();
        }
        jumpMap[0].insert(0); // The frog starts at position 0 with 0 jump distance

        for (int i = 0; i < n; ++i) {
            for (int prevJump : jumpMap[stones[i]]) {
                // Try all possible next jumps from the current stone
                for (int nextJump = prevJump - 1; nextJump <= prevJump + 1; ++nextJump) {
                    if (nextJump > 0 && jumpMap.find(stones[i] + nextJump) != jumpMap.end()) {
                        jumpMap[stones[i] + nextJump].insert(nextJump);
                    }
                }
            }
        }

        // If the last stone has any possible jump distance, then the frog can reach the last stone
        return !jumpMap[stones.back()].empty();
    }
};