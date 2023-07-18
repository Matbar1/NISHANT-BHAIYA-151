class Solution {
 void printLeaves(struct Node* root, vector <int> &res)
    {
        if (root == NULL)
            return;

        printLeaves(root->left, res);

        // Print it if it is a leaf node
        if (!(root->left) && !(root->right))
            res.push_back (root->data);

        printLeaves(root->right, res);
    }

// A function to print all left boundary nodes, except a leaf node.
// Print the nodes in TOP DOWN manner
    void printBoundaryLeft(struct Node* root, vector <int> &res)
    {
        if (root == NULL)
            return;

        if (root->left) {

            // to ensure top down order, print the node
            // before calling itself for left subtree
            res.push_back (root->data);
            printBoundaryLeft(root->left, res);
        }
        else if (root->right) {
            res.push_back (root->data);
            printBoundaryLeft(root->right, res);
        }
        // do nothing if it is a leaf node, this way we avoid
        // duplicates in output
    }

// A function to print all right boundary nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
    void printBoundaryRight(struct Node* root, vector <int> &res)
    {
        if (root == NULL)
            return;

        if (root->right) {
            // to ensure bottom up order, first call for right
            // subtree, then print this node
            printBoundaryRight(root->right, res);
            res.push_back (root->data);
        }
        else if (root->left) {
            printBoundaryRight(root->left, res);
            res.push_back (root->data);
        }
        // do nothing if it is a leaf node, this way we avoid
        // duplicates in output
    }

// A function to do boundary traversal of a given binary tree
public:
    vector <int> boundary(struct Node* root)
    {
        vector <int> res;
        if (root == NULL)
            return res;

        res.push_back (root->data);

        // Print the left boundary in top-down manner.
        printBoundaryLeft(root->left, res);

        // Print all leaf nodes
        printLeaves(root->left, res);
        printLeaves(root->right, res);

        // Print the right boundary in bottom-up manner
        printBoundaryRight(root->right, res);
    }

};