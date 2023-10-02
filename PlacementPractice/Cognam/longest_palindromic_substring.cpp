/*
we use 2 pointer approach from left side
we take diff variable for every i,j
Total 4 cases possible for diff :-
1) if diff = 0 --> i and j are on same position, it means they are always palindromic, mark dp[i][j] = 1
2) if diff = 1 --> i and j are adjacent to each other, so if both char are same (i.e s[i] == s[j]), mark dp[i][j] = 2, as dp[i][j] = 1 when i=j are already palindromic 
3) and all other cases of diff --> check if previous case was a palindromic or not and if s[i] == s[j], and if it is true, then 

dp value stores the maximal length of the palindromic length possible till now

*/




class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLength=0;
        vector<vector<int>> dp(n,vector<int>(n,0)); 
        for(int diff=0;diff<n;diff++){
            for(int i=0,j=i+diff;i<n,j<n;i++,j++){
                // if diff = 0
                if(i==j or diff == 0) 
                    dp[i][j]=1;

                // if diff = 1
                else if(diff==1) 
                    dp[i][j]=(s[i]==s[j]) ? 2 : 0;

                // if diff is other than this
                else {
                    if(s[i]==s[j] && dp[i+1][j-1])
                        dp[i][j] = dp[i+1][j-1]+2; 
                }

                // if the dp[i][j] is not 0, it means it is a palindrome, 
                // then we will check if the length is greater than maxlength, 
                // then we will update maxlength and ans
                if(dp[i][j]) { 
                    if(j-i+1>maxlength) {
                        maxlength = j-i+1;
                        ans = s.substr(i,maxlength); // we will store the substring from index i to maxlength of the palindrome
                    } 
                } 
            }
        }
        return ans;
    }
};