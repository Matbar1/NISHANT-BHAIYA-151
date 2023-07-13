class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
           Node* temp=new Node(0);
    Node *curr=head;
    while (curr != NULL) {  
        if (curr->next==NULL)
            return false;
        if(curr->next==temp)
            return true;
        Node *curr_next=curr->next;
        curr->next=temp;
        curr=curr_next;
    } 
    return false; 
    }

};