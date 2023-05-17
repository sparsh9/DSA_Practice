// Approach 1 (Naive Solution)
// Make a recursive function and for every i, check its twin number and calculate the max twin sum
// O(n*2) will be the time complexity and O(1) space complexity

// Approach 2 (Better than Naive)
// Create a hash map over a single iteration and store the num[i] and its twin as pairs
// run a loop and check the maxsum for the map 
// O(n) is the time complexity and O(n) is the space complexity for the hash map

// Approach 3 using slowptr(move 1 step forward) and fastptr(move 2 step forward) method
// Steps:
// Find the middle node of linked list. (4 in this case)
// Reverse the remaining Linked list.
// Assign next of middle node to NULL.
// Check for all pairs one by one.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMiddleNode(ListNode* head){
        ListNode *slowptr=head;
        // ListNode*fastptr=head;
        ListNode *fastptr=head->next;
        while(fastptr && fastptr->next){
            slowptr=slowptr->next;
            fastptr=fastptr->next->next;
        }
        return slowptr;
    }

    ListNode* reverse(ListNode *head){
        ListNode *prev = NULL,*curr = head, *temp;
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        int ans = 0;
        ListNode* midNode = findMiddleNode(head);
        ListNode* head2 = reverse(midNode->next);
        midNode->next = NULL;
        ListNode* p1 = head,*p2 = head2;
        while(p1 && p2){
            ans = max(ans,(p1->val + p2->val));
            p1 = p1->next;
            p2 = p2->next;
        }
        return ans;
    }
};