class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); i++) {
        inorderMap[inorder[i]] = i;
    }
    
    return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
}

TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                          vector<int>& inorder, int inStart, int inEnd,
                          unordered_map<int, int>& inorderMap) {
    if (preStart > preEnd || inStart > inEnd) {
        return nullptr;
    }
    
    // Create a new node using the value at the current preorder index
    TreeNode* root = new TreeNode(preorder[preStart]);
    
    // Find the index of the root value in the inorder traversal
    int rootIndex = inorderMap[root->val];
    
    // Calculate the number of nodes in the left subtree
    int leftSubtreeSize = rootIndex - inStart;
    
    // Recursively build the left and right subtrees
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSubtreeSize,
                                 inorder, inStart, rootIndex - 1, inorderMap);
    root->right = buildTreeHelper(preorder, preStart + leftSubtreeSize + 1, preEnd,
                                  inorder, rootIndex + 1, inEnd, inorderMap);
    
    return root;
}
};