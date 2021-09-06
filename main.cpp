structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(head == NULL || head->next == NULL) return;
        
        Node* fast = head;
        Node* slow = head;
        
        fast = fast->next->next;
        slow = slow->next;
        
        while( slow && fast && fast->next){
            if(fast == slow) break;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(slow == fast){
            
            slow = head;
            
            if(slow == fast) while(fast->next != slow) fast = fast->next; // if head is the loop node
            
            else {
                while(slow->next != fast->next) { // 
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            
            fast->next = NULL;
        }
        
        
    }
};
