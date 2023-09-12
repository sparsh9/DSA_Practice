class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)return NULL;

        ListNode *a = headA;
        ListNode *b = headB;

        // while a and b are not null and a and b are not equal
        while(a != b){
            a = a == NULL ? headB : a->next; // if a is null then point it to headB else point it to next node
            b = b == NULL ? headA : b->next; // if b is null then point it to headA else point it to next node
        }

        return a;
    }
};

// example of a testcase where a points to null and returns headB
// linkedlist a = [1,3,5,7,9,11,13,15,17,19,21]
// linkedlist b = [2,4,6,8,10,12,14,16,18,20,21]




class Solution {
public:
    int length(ListNode *head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;

        //step1
        int lenA = length(headA), lenB = length(headB);

        //step2
        if(lenA>lenB){
            while(lenA>lenB){
                headA = headA->next;
                lenA--;
            }
        }
        else if(lenA<lenB){
            while(lenA<lenB){
                headB = headB->next;
                lenB--;
            }
        }
        
        //step 3
        while(headA && headB){
            if(headA==headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};