class Solution {
public:
    // Function to find the longest common subsequence
    int helper(string& s1,string& s2,int i,int j,int n1,int n2,vector<vector<int>>& dp){
        // base case
        if(i>=n1 || j>=n2){
            return 0;
        }
        // if already calculated
        if(dp[i][j]!=-1) return dp[i][j];

        // if equal
        int res=0;
        if(s1[i]==s2[j]){
            res=s1[i]+helper(s1,s2,i+1,j+1,n1,n2,dp);
        }
        else{
            // skip1 = skip the current character of string 1
            int skip1 = helper(s1,s2,i+1,j,n1,n2,dp);
            // skip2 = skip the current character of string 2
            int skip2 = helper(s1,s2,i,j+1,n1,n2,dp);
            // take the maximum of both
            res=max(skip1,skip2);
        }

        return dp[i][j]=res;
    }

    int minimumDeleteSum(string s1, string s2) {
        int total=0;
        int n1=s1.size();
        int n2=s2.size();

        // total sum for string 1 and string 2
        for(int i=0;i<n1;++i){
            total+=s1[i];
        }
        for(int i=0;i<n2;++i){
            total+=s2[i];
        }
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        int res=helper(s1,s2,0,0,n1,n2,dp);
        // result = total sum - 2 times sum of longest common subsequence
        return total-(2*res);
    }
};