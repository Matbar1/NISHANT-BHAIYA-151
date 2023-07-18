

vector<int> diagonal(Node *root)
{
    queue<Node*> Q;
    Node *p;
    Q.push(root);
    vector<int> diagonalNode;
    while (!Q.empty())
    {
        p=Q.front();
        Q.pop();
        while (p)
        {
            if(p->left)
                Q.push(p->left);
            //cout<<p->data<<" ";
            diagonalNode.push_back(p->data);
            p=p->right;
        }
    }
    return diagonalNode;
    
}