/*
Approach : We check for the nums2 array itself for the first time. 
Then we store the next greater element of each element in nums2 in a map.
Then we traverse nums1 and find the next greater element of each element in nums1 by checking the map. 

Process of checking the next greater element of each element in nums2:
1) We traverse the array from the end.
2) We check if the stack is empty or not. If it is empty, we store -1 in the map for that element.
3) If the stack is not empty, we check if the top element of the stack is greater than the current element.
4) If it is smaller, we pop the element from the stack.
5) We repeat step 3 and 4 until the stack is empty or the top element of the stack is greater than the current element.
6) If the stack is empty, we store -1 in the map for that element.
7) If the stack is not empty and the condition is satisfied, we store the top element of the stack in the map for that element.
8) We push the current element in the stack.

Here the greater element wrt current element is stored in the map, hence even if we remove the elements from the stack, we can still find the next greater element of the current element.
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        unordered_map<int, int> mp;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty()) {
                mp[nums2[i]] = -1;
            } else {
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};