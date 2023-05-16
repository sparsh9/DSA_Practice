class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *curr = head->next->next;
        ListNode *prev = head;
        head = head->next;
        head->next = prev;
        // prev->next = curr;

        while(curr->next != nullptr && curr != nullptr){
            prev->next = curr->next;
            prev = curr;

            ListNode *temp = curr->next->next;
            curr->next->next = curr;
            curr = temp;
        }
        prev->next = curr;
        return head;
    }
};