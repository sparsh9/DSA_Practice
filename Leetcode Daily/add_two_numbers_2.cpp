// Approach 1 (Using traversal)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); // Create a dummy node as the head of the resulting linked list
        ListNode* curr = dummy; // Pointer to traverse the linked list
        int carry = 0; // Carry value for addition
        
        while (l1 || l2 || carry) {
            int sum = carry; // Initialize sum with the carry value
            
            if (l1) {
                sum += l1->val; // Add the current digit of l1 to the sum
                l1 = l1->next; // Move l1 pointer to the next digit
            }
            
            if (l2) {
                sum += l2->val; // Add the current digit of l2 to the sum
                l2 = l2->next; // Move l2 pointer to the next digit
            }
            
            carry = sum / 10; // Calculate the carry for the next digit
            int digit = sum % 10; // Calculate the current digit
            
            ListNode* newNode = new ListNode(digit); // Create a new node for the current digit
            curr->next = newNode; // Set the next pointer of the current node to the new node
            curr = curr->next; // Move the current pointer to the next node
        }
        
        ListNode* result = dummy->next; // Get the resulting linked list (excluding the dummy node)
        delete dummy; // Delete the dummy node
        
        return result; // Return the resulting linked list
    }
};




// Approach 2: Using Stacks


class Solution {
public:
    // Helper function to perform addition on two linked lists represented by stacks
    ListNode* Helper(ListNode* l1, ListNode* l2) {
        stack<int> stack1, stack2;

        // Push each digit of the first linked list into stack1
        while (l1 != nullptr) {
            stack1.push(l1->val);
            l1 = l1->next;
        }

        // Push each digit of the second linked list into stack2
        while (l2 != nullptr) {
            stack2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* result = nullptr; // Linked list to store the result of addition
        int carry = 0; // Carry value for addition

        // Perform addition digit by digit until both stacks and carry are empty
        while (!stack1.empty() || !stack2.empty() || carry != 0) {
            int digit1 = !stack1.empty() ? stack1.top() : 0; // Retrieve the top digit from stack1, or 0 if stack1 is empty
            int digit2 = !stack2.empty() ? stack2.top() : 0; // Retrieve the top digit from stack2, or 0 if stack2 is empty

            int sum = digit1 + digit2 + carry; // Add the digits along with the carry
            int digit = sum % 10; // Calculate the current digit of the result
            carry = sum / 10; // Calculate the carry for the next digit

            ListNode* newNode = new ListNode(digit); // Create a new node for the current digit
            newNode->next = result; // Set the next pointer of the new node to the current result
            result = newNode; // Update the result as the new node

            if (!stack1.empty())
                stack1.pop(); // Pop the top digit from stack1 if it is not empty
            if (!stack2.empty())
                stack2.pop(); // Pop the top digit from stack2 if it is not empty
        }

        return result; // Return the resulting linked list
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = Helper(l1, l2); // Call the helper function to perform addition
        return ans; // Return the result
    }
};


