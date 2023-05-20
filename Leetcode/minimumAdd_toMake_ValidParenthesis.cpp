// Approach 1 (making seperate variables for opening and closing brackets)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int open = 0;
        int close = 0;

        for(int j=0;j<s.length();j++){

            if((open - close) == 0 && s[j] == ')'){
                    ans++;
            }
            else if(s[j] == '(')
                open++;
            else
                close++;
        }
        ans += (open-close);
        return ans;
    }
};

// Approach 2 (using stacks)
// Here we are always pairing the opposites and then at last calculating the 
// size of the stack where we are unable to find the pairs
class Solution {
public:
int minAddToMakeValid(string s) 
{
    stack<char> st;//create a Stack
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')//whenever their is open bracket insert on stack
            st.push('(');
        else 
        {
            if(!st.empty() && st.top()=='(')//if their is open bracket on the top of stack and stack is not empty, then pop
                st.pop();
            else
                st.push(')');//otherwise push closing bracket on stack
        }
    }
    return st.size();//atlast return stack size
}
};