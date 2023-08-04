#include <vector>

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootX] = rootY;
            rank[rootY]++;
        }
    }
};

class Solution {
public:
    int regionsBySlashes(std::vector<std::string>& grid) {
        int N = grid.size();
        int size = 4 * N * N;
        UnionFind uf(size);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int root = 4 * (i * N + j);
                char cell = grid[i][j];

                if (cell == '/') {
                    uf.unite(root, root + 3);
                    uf.unite(root + 1, root + 2);
                } else if (cell == '\\') {
                    uf.unite(root, root + 1);
                    uf.unite(root + 2, root + 3);
                } else {
                    uf.unite(root, root + 1);
                    uf.unite(root + 1, root + 2);
                    uf.unite(root + 2, root + 3);
                }

                if (i + 1 < N) {
                    uf.unite(root + 2, (root + 4 * N));
                }
                if (j + 1 < N) {
                    uf.unite(root + 1, (root + 4 + 3));
                }
            }
        }

        int regions = 0;
        for (int i = 0; i < size; i++) {
            if (uf.find(i) == i) {
                regions++;
            }
        }

        return regions;
    }
};
