class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prevNode=NULL,*nextNode = NULL;

        while(head){
            nextNode = head->next; // head ke next ko store karlo for future
            head->next = prevNode; // ab head ko palat do, uska next uska prev hoga
            prevNode = head; // 
            head = nextNode; // ab naya head next nodes ke liye current nextNode hoga
        }
        return prevNode;
    }
};

