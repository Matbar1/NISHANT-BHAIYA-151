class Solution
{
  public:
   Node *concatenate(Node *leftList, Node *rightList)
    {    
        //if either of the lists is empty, we return the other list. 
        if (leftList == NULL)
            return rightList;
        if (rightList == NULL)
            return leftList;
            
        //storing the last node of left list. 
        Node *leftLast = leftList->left;
        //storing the last node of right list. 
        Node *rightLast = rightList->left;
        
        
        //connecting the last node of Left list with the first 
        //node of the right list.
        leftLast->right = rightList;
        rightList->left = leftLast;
        
        //left of first node points to the last node in the list.
        leftList->left = rightLast;
        
        //right of last node refers to the first node of the list.
        rightLast->right = leftList;
        return leftList;
    }
    
    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root)
    {
        if (root == NULL)
            return NULL;
        
        //calling the function for left and right subtrees recursively.    
        Node *left = bTreeToCList(root->left);
        Node *right = bTreeToCList(root->right);
        
        
        //making a circular linked list of single node. To do so, we make the  
        //right and left pointers of this node point to itself.
        root->left = root->right = root;
        
        
        //firstly, concatenating the left list with the list with 
        //single node i.e. current node. 
        //then concatenating the returned list with the right list. 
        return concatenate(concatenate(left, root), right);
    }
};
    //Function to 