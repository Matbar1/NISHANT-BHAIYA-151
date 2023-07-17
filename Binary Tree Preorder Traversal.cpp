class Solution {
    void  preorderTraversalHelper(TreeNode* root, vector<int> &res)
    {
        if(root==NULL)
        {
            return;
        }
        res.push_back(root->val);
        preorderTraversalHelper(root->left,res);
        preorderTraversalHelper(root->right,res);

    
}
public:
    vector<int> preorderTraversal(TreeNode* root) { 
        vector<int> res;
        preorderTraversalHelper(root,res);
        return res;
    }
};

    