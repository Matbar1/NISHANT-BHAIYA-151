class Solution {
    public:
   
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        
        helper(root, 0, result);
        return result;
    }
    
    void helper(TreeNode* node, int level, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        
        if (level == result.size()) {
            result.push_back(node->val);
        } else {
            result[level] = node->val;
        }
        
        helper(node->left, level + 1, result);
        helper(node->right, level + 1, result);
    }
};
