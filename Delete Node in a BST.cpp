class Solution {
public:
     TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr; // Key not found
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key); // Delete from the left subtree
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key); // Delete from the right subtree
        } else {
            // Found the node to be deleted

            if (root->left == nullptr) {
                // Case 1: No left child or no children
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                // Case 2: No right child
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                // Case 3: Both left and right children exist

                // Find the inorder successor (smallest value in the right subtree)
                TreeNode* successor = findSuccessor(root->right);
                
                // Replace the value of the current node with the value of the successor
                root->val = successor->val;

                // Delete the successor from the right subtree
                root->right = deleteNode(root->right, successor->val);
            }
        }

        return root;
    }

private:
    TreeNode* findSuccessor(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};