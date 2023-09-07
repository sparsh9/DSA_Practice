// Approach : Use 3 pointers 
// prev : points to the node just before the duplicates start so that it can be removed using this
// curr : points to the node which is currently being checked and (also it is starting of the duplicates)
// currEnd : points to the last node of the duplicates so that we can move prev to currEnd->next directly

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // currEnd is the last node of the duplicates
        ListNode *prev = NULL, *curr = head,*currEnd = head;
        while(curr != NULL){
            // if curr->next is not null and curr->val == curr->next->val
            // then move currEnd until currEnd->next->val != curr->val
            if(curr->next != NULL && curr->val == curr->next->val){
                while(currEnd->next != NULL && currEnd->next->val == curr->val){
                    currEnd = currEnd->next;
                }
                // if prev is null then it means we have to delete the first node itself
                if(prev == NULL){
                    head = currEnd->next;
                    curr = head;
                    currEnd = head;
                }
                // otherwise
                else{
                    prev->next = currEnd->next;
                    curr = currEnd->next;
                }
            }
            // otherwise move prev, curr and currEnd
            else{
                prev = curr;
                curr = curr->next;
                currEnd = curr;
            }
        }
        return head;
    }
};