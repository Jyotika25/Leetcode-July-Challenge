/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
    if(head==NULL) return NULL;

    Node* ptr=head ,*temp=NULL,*node;
    while(ptr)
    {
        if(!ptr->child)
        {  
            ptr=ptr->next;
        }
        else
        {   if(ptr->next)               
            temp=ptr->next;
            node=flatten(ptr->child);
            ptr->child=NULL;
            node->prev=ptr;
            ptr->next=node;
            if(temp)
            {
                while(ptr->next)   
                ptr=ptr->next;
                
                ptr->next=temp;
                temp->prev=ptr;
                ptr=ptr->next;
            }
            
        }
    }   
    
    return head;
    
}
};
