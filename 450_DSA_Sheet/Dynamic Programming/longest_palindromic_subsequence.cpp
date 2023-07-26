// Approach 1 (Using Power Set Method and then checking for palindrome)

class Solution {
public:
    bool isPalindrome(string s){
        int n = s.length();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1])
                return false;
        }
        return true;
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<(1<<n);i++){
            string temp = "";
            for(int j=0;j<n;j++){
                if(i&(1<<j))
                    temp+=s[j];
            }
            if(isPalindrome(temp))
                ans = max(ans, (int)temp.length());
        }
        return ans;
    }
};


// Approach 2 (Using LCS Method)
// Here the main logic is that as the palindrome is a string which is same as its reverse,
// so we will find the LCS of the given string and its reverse.
// Now the length of the LCS will be the length of the longest palindromic subsequence.

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string t = s;
        reverse(t.begin(), t.end());
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        // base case : for indexes at 0, we will fill the dp array with 0
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int j=0;j<=n;j++)
            dp[0][j]=0;

        // now we will fill the dp array
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                // if it matches then we will move to the next character
                if(s[i-1]==t[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                // if it does not matches, then we will simply make the dp[i][j] = 0
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[n][n];
    }
};