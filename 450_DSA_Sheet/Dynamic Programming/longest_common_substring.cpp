// Here apart from the problem of longest common subsequences,
// we have to maintain the continuity of the substring.
// so in the case of mismatch, we will make the dp[i][j] = 0



// Approach using Recursion + Memoization

class Solution{
    public:
    int ans = 0; // final answer of the longest substring with length updated everytime
    int helper(string a, string b, int i, int j, vector<vector<int>> &dp){
        // base case
        if(i >= a.size() || j >= b.size()) {
            return 0;
        }
        // if already calculated
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxi = 0;
        // when they meet, then till that only longest common subtring possible otherwise
        // after that the continuity will break
        if(a[i] == b[j]) {
            maxi = helper(a, b, i + 1, j + 1, dp) + 1;
            ans = max(ans, maxi); 
            // max of the all the possible longest common substrings and
            // the longest common substring till now
        }
        else {
            maxi = 0;
            // if does not match then simply put 0 
            // because continuity will break otherwise
        }
        
        return dp[i][j] = maxi;
    }
    
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n, vector<int> (m, -1));
        // dp[i][j] represents longest common subtring till index1 and index2 
        // of strings1 and strings2 as = dp[index1][index2] from 0 to n-1 and 0 to m-1

        // here we are running for loop for all the possible starting points of both the substrings
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                helper(S1, S2, i, j, dp);
            }
        }
        
        return ans;
    }
};



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


