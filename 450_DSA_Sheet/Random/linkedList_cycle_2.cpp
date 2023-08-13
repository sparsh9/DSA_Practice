class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // first checking if there exists a cycle
        bool cycle = false;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next; // moving 1 step
            fast = fast->next->next; // moving 2 steps (2 times)

            if(slow == fast) {
                cycle = true;
                break;
            }
        }

        // if there is no cycle
        if(!cycle) {
            return NULL;
        }

        // if there is a cycle

        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow; // or fast   
    }
};