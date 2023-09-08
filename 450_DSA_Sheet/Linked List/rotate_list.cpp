// Approach : Use 2 pointers
// curr : taken to last node and then connected to head
// prev : taken to the node just before the end node and then later connection to last node is broken and pointed to null
// after this, it is one iteration, now reset things for next iterartions
// curr points to head and prev points to null

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *curr = head, *prev = NULL;
        // if head is null or head->next is null or k is 0 then return head
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }

        // to optimise it for large values of k

        int length = 0;
        // find length of the list
        while(curr != NULL){
            ++length;
            curr = curr->next;
        }
        // if k is greater than length then take k = k % length
        if(k > length){
            k = k % length;
        }
        // if k is 0 then return head
        if(k == 0){
            return head;
        }



        while(k--){
            // now reset to original position and also for next iterations
            curr = head;
            prev = NULL;

            // move curr to the end and prev to the node just before the end
            while(curr->next != NULL){
                prev = curr;
                curr = curr->next;
            }
            // now curr is at the end and prev is at the node just before the end
            curr->next = head;
            head = curr;
            prev->next = NULL;

        }
        return head;
    }
};