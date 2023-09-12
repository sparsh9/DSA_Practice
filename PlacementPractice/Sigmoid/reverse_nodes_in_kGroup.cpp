// Approach : Use concept of reverse linked list until k nodes and 
// then point the last node of the reversed linked list to the next k nodes

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int x = k;
        ListNode* p = head;
        // perform till x is greater than 0 and p is not null
        while(x>0 && p){
            p = p->next;
            x--;
        }
        // till here the pointer p will be at the k+1th node


        // if x is 0 then we have k nodes to reverse, now perform "reverse linked list" operation
        // on these k nodes and point its last node to the next k nodes
        if(x==0){
            ListNode* prevNode = NULL,*nextNode = NULL,*currNode = head;
            while(currNode != p){
                nextNode = currNode->next;
                currNode->next = prevNode;
                prevNode = currNode;
                currNode = nextNode;
            }

            // here in the intial run, prevNode will store the head of the new reversed linked list,therefore we equal our head to prevNode

            // here the head will be the last node of the reversed linked list
            head->next = reverseKGroup(p,k); // this will be the next head of the reversed linked list
            
            return head = prevNode; 
        }
        else{
            return head;
        }
    }
};