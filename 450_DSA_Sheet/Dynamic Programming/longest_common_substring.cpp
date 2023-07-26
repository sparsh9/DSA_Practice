// Here apart from the problem of longest common subsequences,
// we have to maintain the continuity of the substring.
// so in the case of mismatch, we will make the dp[i][j] = 0

// Approach using Tabulation

class Solution{
    public:
    
    int longestCommonSubstr (string text1, string text2, int n, int m)
    {
        if(n==0 || m==0)
            return 0;
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        // base case : for indexes at 0, we will fill the dp array with 0
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int j=0;j<=m;j++)
            dp[0][j]=0;

        int ans = 0;    

        // now we will fill the dp array
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                // if it matches then we will move to the next character
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                // if it does not matches, then we will simply make the dp[i][j] = 0
                else
                    dp[i][j]=0
            }
        }
        
        return ans;
    }
};