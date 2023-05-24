// Approach 1 (Using stacks and greedy)
// What we'll do, use the stack to keep track of selected character's. We try to put the character's only once & maintain the lexicographicall smallest one. So, how we do that :-
// If the stack is empty, we'll put the current character into our stack
// We'll also keep here boolean array which will mark, whether we have seen this character or not. So, that if we are getting again the same character and we have already seen that. We'll ignore that character.
// So, the length of boolean array will be 26
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> nextPossibleIndex(26, 0);
        for (int i = 0; i < s.length(); i++){
            nextPossibleIndex[s[i] - 'a'] = i; // tracks the next possible index of duplicate characters so that we will take it lately
        }
        
        vector<bool> seen(26, false); // keep track seen
        stack<char> st;
        
        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            if (seen[curr]) continue; // if seen continue as we need to pick one char only
            // Here in the while loop we are checking 3 conditions at a same time :
            // 1) stack size is greater than 0
            // 2) new element is lesser than stack's top element
            // 3) current element's index is smaller/less than the nextPossibleIndex of that same characters
            while(st.size() > 0 && st.top() > s[i] && i < nextPossibleIndex[st.top() - 'a']){
                seen[st.top() - 'a'] = false; // pop out and mark unseen
                st.pop();
            }
            st.push(s[i]); // add into stack
            seen[curr] = true; // mark seen
        }
        
        string ans = "";
        while (st.size() > 0){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};