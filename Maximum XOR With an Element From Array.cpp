struct TrieNode {
    TrieNode *next[2] = {};
    int minVal = INT_MAX;
};
class Solution {
    void add(TrieNode *node, int n) {
        for (int i = 31; i >= 0; --i) {
            int b = n >> i & 1;
            if (node->next[b] == NULL) node->next[b] = new TrieNode();
            node = node->next[b];
            node->minVal = min(node->minVal, n);
        }
    }
    int maxXor(TrieNode *node, int x, int m) {
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            int b = x >> i & 1;
            if (node->next[1 - b] && node->next[1 - b]->minVal <= m) {
                node = node->next[1 - b];
                ans |= 1 << i;
            } else if (node->next[b] && node->next[b]->minVal <= m) node = node->next[b];
            else return -1;
        }
        return ans;
    }
public:
    vector<int> maximizeXor(vector<int>& A, vector<vector<int>>& Q) {
        TrieNode root;
        vector<int> ans;
        for (int n : A) add(&root, n);
        for (auto &q : Q) {
            int x = q[0], m = q[1];
            ans.push_back(maxXor(&root, x, m));
        }
        return ans;
    }
};