// Approach : Delete kth node from start instead of nth node from end

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length;
        ListNode *curr = head;
        while(curr != NULL){
            ++length;
            curr = curr->next;
        }
        
        // now nth from end is length - n + 1 from start
        int pos = length - n + 1;
        
        // if it is the first node itself
        if(pos == 1){
            head = head->next;
            return head;
        }
        // otherwise
        curr = head;
        ListNode *prev = NULL;
        while(pos > 1){
            prev = curr;
            curr = curr->next;
            --pos;
        }
        prev->next = curr->next;
        return head;
    }
};



// Approach : Two pointer approach

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // intially slow and fast both are at head
        ListNode *slow = head, *fast = head;
        // move fast n times
        while(n--){
            fast = fast->next;
        }
        // if fast is null then it means we have to delete the first node itself
        if(fast == NULL){
            head = head->next;
            return head;
        }
        // otherwise move both slow and fast until fast reaches the end
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        // now slow is at the node just before the node to be deleted
        slow->next = slow->next->next;
        
        return head;
    }
};