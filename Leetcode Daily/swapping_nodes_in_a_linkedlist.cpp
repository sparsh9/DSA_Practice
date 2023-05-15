// Approach 1 using 2 seperate loops for both left and right positions
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode left = head;
        ListNode right = head;
        int cnt = 0;

        // for left kth node
        while(left != null){
            cnt++;
            if(cnt == k)
                break;
            left = left.next;
        }
        int cnt = 1;
		// for right kth node
        while (left != null && cnt != k) {
            cnt++;
            left = left.next;
        }

        // swap their values
        int temp = left.val;
        left.val = right.val;
        right.val = temp;

        return head;
    }
};

// Approach 2 using 2 pointers
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(--k){
            fast = fast->next;
        }
        ListNode* left = fast;
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        swap(left->val,slow->val);
        return head;
    }
};


// Approach 3 by swapping the nodes (most safe option if in case we are not able to swap node values)
// best approach for interview point of view

class Solution {
public:
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode base;
    base.next = head;
    ListNode* a = &base;
    while (k > 1) {
      --k;
      a = a->next;
    }  // Now a is the parent of the kth node.

    ListNode* b = &base;
    ListNode* end = a->next->next;
    while (end != nullptr) {
      b = b->next;
      end = end->next;
    }  // Now b is the parent of the -kth node.
    if (a != b) {
      swap(a->next, b->next);
      swap(a->next->next, b->next->next);
    }
    return base.next;
  }
};