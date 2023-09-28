class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        // if head is null or head is the only node in the linked list then return head (no change
        if(!head || !head->next || !head->next->next) return head;
        
        ListNode *oddStart = head;
        ListNode *odd =  head; // making a temporary odd linked list
        ListNode *even = head->next; // making a temporary even linked list
        ListNode *evenStart = head->next;

        while(odd->next && even->next){
            odd->next = even->next; // connecting all odds
            even->next = odd->next->next; // connecting all evens
            odd = odd->next; // moving odd pointer to next odd
            even = even->next; // moving even pointer to next even
        }
        odd->next = evenStart;
        return oddStart; // can also be return head; as it is same as head is unchanged
    }
};