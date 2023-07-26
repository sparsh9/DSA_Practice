// In the problems related to strings , we take 2 possibilities
// match or not match
// unlike in the case of the arrays where we had 2 similar possibilities : take or not take

// Approach 1: Recursion (match or not match)

class Solution {
public:
    int helper(string &text1,string &text2,int n,int m){
        // base case : if any moment the index of any of the string becomes -1, then we will return 0
        if(n<0 || m<0)
            return 0;


        // if it matches then we will move to the next character
        if(text1[n]==text2[m])
            return 1+helper(text1,text2,n-1,m-1);
        // if it does not matches, then we will take the max of the 2 possibilities
        // 1. we will move to the next character of text1
        // 2. we will move to the next character of text2
        else
            return max(helper(text1,text2,n-1,m),helper(text1,text2,n,m-1)); // basically its 0 + max(...)        
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        if(n==0 || m==0)
            return 0;
        
        return helper(text1,text2,n-1,m-1);
    }
};



// Approach 2: Recursion + Memoization (match or not match)

class Solution {
public:
    int helper(string &text1,string &text2,int n,int m,vector<vector<int>> &dp){
        // base case : if any moment the index of any of the string becomes -1, then we will return 0
        if(n<0 || m<0)
            return 0;

        // if the value is already present in the dp array, then we will return it
        if(dp[n][m]!=-1)
            return dp[n][m];

        // if it matches then we will move to the next character
        if(text1[n]==text2[m])
            return dp[n][m]=1+helper(text1,text2,n-1,m-1,dp);
        // if it does not matches, then we will take the max of the 2 possibilities
        // 1. we will move to the next character of text1
        // 2. we will move to the next character of text2
        else
            return dp[n][m]=max(helper(text1,text2,n-1,m,dp),helper(text1,text2,n,m-1,dp)); // basically its 0 + max(...)        
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        if(n==0 || m==0)
            return 0;
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(text1,text2,n-1,m-1,dp);
    }
};

// Now we are using shifting of indexes in the dp array
// where n will be treated as n-1 and m will be treated as m-1 in the helper function
// and we will pass n and m as n+1 and m+1 in the dp array
// this is done to avoid the base case of n<0 and m<0

class Solution {
public:
    int helper(string &text1,string &text2,int n,int m,vector<vector<int>> &dp){
        // base case : if any moment the index of any of the string becomes -1, then we will return 0
        if(n==0 || m==0)
            return 0;

        // if the value is already present in the dp array, then we will return it
        if(dp[n][m]!=-1)
            return dp[n][m];

        // if it matches then we will move to the next character
        if(text1[n-1]==text2[m-1])
            return dp[n][m]=1+helper(text1,text2,n-1,m-1,dp);
        // if it does not matches, then we will take the max of the 2 possibilities
        // 1. we will move to the next character of text1
        // 2. we will move to the next character of text2
        else
            return dp[n][m]=max(helper(text1,text2,n-1,m,dp),helper(text1,text2,n,m-1,dp)); // basically its 0 + max(...)        
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        if(n==0 || m==0)
            return 0;
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return helper(text1,text2,n,m,dp);
    }
};






// Approach 3: Tabulation (match or not match) using the shifted indexes

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        if(n==0 || m==0)
            return 0;
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        // base case : for indexes at 0, we will fill the dp array with 0
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int j=0;j<=m;j++)
            dp[0][j]=0;

        // now we will fill the dp array
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                // if it matches then we will move to the next character
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                // if it does not matches, then we will take the max of the 2 possibilities
                // 1. we will move to the next character of text1
                // 2. we will move to the next character of text2
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]); // basically its 0 + max(...)        
            }
        }
        
        return dp[n][m];
    }
};



// Approach 4: Tabulation (match or not match) using the shifted indexes and space optimization

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        if(n==0 || m==0)
            return 0;
        
        vector<int> prev(m+1,0),curr(m+1,0);

        // base case : for indexes at 0, we will fill the dp array with 0
        for(int j=0;j<=m;j++)
            prev[j]=0;
        
        // now we will fill the dp array
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                // if it matches then we will move to the next character
                if(text1[i-1]==text2[j-1])
                    curr[j]=1+prev[j-1];
                // if it does not matches, then we will take the max of the 2 possibilities
                // 1. we will move to the next character of text1
                // 2. we will move to the next character of text2
                else
                    curr[j]=max(prev[j],curr[j-1]); // basically its 0 + max(...)        
            }
            prev=curr;
        }

        return curr[m];
    }
};