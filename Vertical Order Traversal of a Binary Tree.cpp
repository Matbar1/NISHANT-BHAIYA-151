class Solution {
 map<int, map<int, multiset<int>>> m;
    void dfs(TreeNode *root, int x, int y) {
        if (!root) return;
        m[x][y].insert(root->val);
        dfs(root->left, x - 1, y + 1);
        dfs(root->right, x + 1, y + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        for (auto &[x, mm] : m) {
            ans.emplace_back();
            for (auto &[y, vals] : mm) {
                for (int n : vals) ans.back().push_back(n);
            }
        }
        return ans;
    }
};