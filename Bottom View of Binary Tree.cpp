//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
     vector <int> bottomView(Node *root)
    {
        vector <int> res;
        if (root == NULL)
            return res;
    
        //initializing a variable 'hd' with 0 for the root element.
        int hd = 0;
    
        //TreeMap which stores key value pair sorted on key value.
        map<int, int> m;
        map<Node  *, int> mh;
    
        //Queue to store tree nodes in level order traversal.
        queue<Node *> q;
    
        //assigning initialized horizontal distance value to 
        //root node and adding it to the queue.
        mh[root] = hd;
        q.push(root);
    
        
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
    
            //extracting the horizontal distance value from dequeued tree node.
            hd = mh[temp];
    
            //putting the dequeued tree node to TreeMap having key as  
            //horizontal distance. Every time we find a node having same
            //horizontal distance we need to replace the data in the map.
            m[hd] = temp->data;
    
            //if the dequeued node has a left child, adding it to 
            //the queue with a horizontal distance hd-1.
            if (temp->left != NULL)
            {
                mh[temp->left] = hd-1;
                q.push(temp->left);
            }
    
            //if the dequeued node has a right child adding it to 
            //the queue with a horizontal distance hd+1.
            if (temp->right != NULL)
            {
                mh[temp->right] = hd+1;
                q.push(temp->right);
            }
        }
        
        //traversing the map elements and storing nodes in the list.
        for (map<int, int>::iterator i = m.begin(); i != m.end(); ++i)
            res.push_back (i->second);
            
        //returning the output list.
        return res;
    }
};