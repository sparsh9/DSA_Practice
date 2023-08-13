// Approach (Using slow and fast pointer)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // initially slow and fast are at same position
        ListNode* slow = head;
        ListNode* fast = head;

        // checking if curr fast and fast->next is not null
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next; // moving 1 step
            fast = fast->next->next; // moving 2 steps (2 times)

            if(slow == fast) {
                return true;
            }
        }

        return false;   
    }
};