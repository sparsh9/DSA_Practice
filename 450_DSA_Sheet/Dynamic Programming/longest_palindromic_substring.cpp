// Approach : Tabulation

class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.size();
        int maxlength = 0;  
        string ans;
        vector<vector<int>>dp(n,vector<int>(n,0));
        // we are moving diagonally from middle diagonal to the right most diagonal
        // (i,j=i) -> (i,j=i+1) -> (i,j=i+2) and so on till (i,j=n-1)
        for(int diff = 0;diff<n;diff++) {
            for(int i=0,j=i+diff; j<n; i++, j++){
                // if the difference is 0, then we will simply make dp[i][j] = 1 as
                // it is a single character and it is a palindrome
                if(i==j) 
                    dp[i][j]=1;

                // if the difference is 1 which means there are 2 characters, then we will check if the characters are same
                // then we will make dp[i][j] = 2 as it is a palindrome otherwise we will make it 0
                else if(diff==1) 
                    dp[i][j]=(s[i]==s[j]) ? 2 : 0;
                
                // if the difference is greater than 1, then we will check if the characters are same
                // then we will make dp[i][j] = dp[i+1][j-1]+2 as it is a palindrome
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