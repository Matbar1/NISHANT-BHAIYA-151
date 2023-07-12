
class Solution{
    public:
/* Should return data of middle node. If linked list is empty, then  -1*///
int getMiddle(Node *head)
{
    Node* temp=head;
    Node* mid=head;
   
    if(head==NULL)
        return -1;
    
   while( mid != NULL  &&  mid->next != NULL )
    {  
        mid=mid->next->next;
        // this pointer moves 2 nodes ahead everytime loop is run
        
        temp=temp->next;
        // this pointer moves 1 node ahead everytime loop is run
    }
    
    // since temp was moving with half speed, it is there at halfway point
    return temp->data;
}

};