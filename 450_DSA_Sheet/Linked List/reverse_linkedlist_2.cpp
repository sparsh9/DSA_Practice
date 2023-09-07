class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int L, int R) {
        ListNode *dummy=new ListNode(); // null
        ListNode *prev=dummy,*left=head,*right=head,*forw=head->next;
        dummy->next=head;//we have declared dummy variable and initialize its next to head
		
        int diff=(R-L);//we have stored the difference between R and L
        while(--L){//we are traversing to the left node 
            prev=left;
            left=forw;
            right=forw;
            forw=forw->next;
        }
        
        // tab tak reverse karo jabtak diff = 0 na hojaye
        while(diff--){//after we reach the left node we will start reversing the linked list
            ListNode*temp=forw->next;
            forw->next=right;
            right=forw;
            forw=temp;
        }
        prev->next=right;
        left->next=forw;
        return dummy->next;
    }
};