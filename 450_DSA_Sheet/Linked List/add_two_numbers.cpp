class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        int carry = 0;
        while(l1 != nullptr or l2 != nullptr){
            int sum = carry;
            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum/10;
            ListNode* newNode = new ListNode(sum%10); // val for the node
            // agar head khali hai toh usmein add kardo
            if(head == nullptr){
                head = newNode;
            }
            // nahi toh last node tak jao and uske next mein add kardo
            else{
                ListNode* temp = head;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        // agar carry bacha hai toh usko bhi add kardo
        if(carry > 0){
            ListNode* newNode = new ListNode(carry);
            ListNode* temp = head;
            // last node tak jao and uske next mein add kardo
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        return head;
    }
};