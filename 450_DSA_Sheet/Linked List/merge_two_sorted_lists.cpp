class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        // jab tak dono linked list mein se koi bhi bacha hai
        while(list1 != NULL && list2 != NULL){
            // agar list1 ka head chota hai list2 ke head se
            if(list1->val < list2->val){
                // agar head khali hai toh usmein add kardo
                if(head == NULL){
                    head = list1;
                    tail = list1;
                }
                // nahi toh tail ke next mein add kardo
                else{
                    tail->next = list1;
                    tail = tail->next;
                }
                list1 = list1->next;
            }
            // agar list2 ka head chota hai list1 ke head se
            else{
                // agar head khali hai toh usmein add kardo
                if(head == NULL){
                    head = list2;
                    tail = list2;
                }
                // nahi toh tail ke next mein add kardo
                else{
                    tail->next = list2;
                    tail = tail->next;
                }
                list2 = list2->next;
            }
        }
        // agar list1 mein bacha kuch hai toh usko tail ke next mein add kardo
        if(list1 != NULL){
            if(head == NULL){
                head = list1;
            }
            else{
                tail->next = list1;
            }
        }
        // agar list2 mein bacha kuch hai toh usko tail ke next mein add kardo
        if(list2 != NULL){
            if(head == NULL){
                head = list2;
            }
            else{
                tail->next = list2;
            }
        }
        return head;
    }
};