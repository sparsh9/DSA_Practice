// Approach : Make 2 seperate linkedlists for elements smaller than x and greater than x. 
// Then attach the smaller linkedlist to the greater linkedlist

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Here we are making 2 linkedlists. 1 for elements smaller than x and other for elements greater than x
        ListNode smaller(0),greater(0);
        ListNode *smaller_ptr = &smaller, *greater_ptr = &greater;

        while(head){
            // if value smaller than x, then put the element in the smaller linkedlist
            if(head->val < x){
                smaller_ptr->next = head;
                smaller_ptr = smaller_ptr->next;
            }
            // otherwise in the greater linkedlist
            else{
                greater_ptr->next = head;
                greater_ptr = greater_ptr->next;
            }
            //move till last node
            head = head->next;
        }

        // make last node of the larger linkedlist as NULL
        greater_ptr->next = NULL;
        // attach the smaller linkedlist to the greater linkedlist
        smaller_ptr->next = greater.next;

        return smaller.next; // this signifies the head of the smaller linkedlist
    }
};
