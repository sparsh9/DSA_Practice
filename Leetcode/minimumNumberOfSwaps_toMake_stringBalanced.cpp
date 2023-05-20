// Approach 1
// We maintain a balance variable and when always try to nullify the variable
// Whenever we get a balanced pair of parenthesis and if there is any moment when
// there is starting with closig bracket or there is more number of closing bracket
// then we increase the count of swaps needed.
class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int balance = 0, swaps = 0, j=n-1;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '[') balance++;
            else balance--;

            if(balance < 0)
            {
                while(i<j && s[j] != '[') j--;
                swap(s[i], s[j]);
                swaps++;
                balance = 1;
            }
        }
        return swaps;
    }
};