// Approach 1
// for input of 0001100111
// count of consecutive same numbers are 3 2 2 3
// As only consecutive substrings are valid and there should be equal no of 0's and 1's hence,
// taking the minimum condition will ensure that the substring has equal number of both.
// therefore for 1st pair : 2 substrings are possible = min(3,2)
// similarly for 2nd pair : 2 substrings are possible = min(2,2)
// similarly for 2nd pair : 2 substrings are possible = min(2,3)
// therefore total = 2 + 2 + 2 = 6
class Solution {
public :
    int countBinarySubstrings(string s) {
        int cur = 1, pre = 0, res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) cur++;
            else {
                res += min(cur, pre);
                pre = cur;
                cur = 1;
            }
        }
        return res + min(cur, pre);
    }
};