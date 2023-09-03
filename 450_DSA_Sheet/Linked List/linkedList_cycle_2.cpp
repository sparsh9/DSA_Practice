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
            cout << "Current Nodes in while loop" << slow->val << " " << fast->val << endl;

            if(slow == fast) {
                cycle = true;
                break;
            }
        }

        // if there is no cycle
        if(!cycle) {
            return NULL;
        }
        
        // print current slow and fast nodes
        cout << "Current Nodes after detecting cycle" << slow->val << " " << fast->val << endl;


        // if there is a cycle
        slow = head;
        cout << "Current Nodes after setting slow to head" << slow->val << " " << fast->val << endl;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
            cout << "Current Nodes in while loop" << slow->val << " " << fast->val << endl;
        }
        return slow; // or fast   
    }
};