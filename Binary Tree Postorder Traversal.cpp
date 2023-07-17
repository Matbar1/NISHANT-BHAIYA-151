class Solution {
    void postorderTraversalHelper(TreeNode* root,  vector<int> &result)
    {
        if(root==NULL)
        {
            return;
        }
        postorderTraversalHelper(root->left, result);
        postorderTraversalHelper(root->right, result);
        result.push_back(root->val);

    
}
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderTraversalHelper(root,result);
   
    return result;
}
};

        
    
