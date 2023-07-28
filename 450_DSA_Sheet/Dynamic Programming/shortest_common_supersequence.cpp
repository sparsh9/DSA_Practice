// let "brute" and "groot" are two strings and we have to find the shortest string that has both "brute" and "groot" as subsequences.
// so in the prcocess , let's assume that we take elements of string 1 first and then of string 2 in the supersequence.
// therefore, the common characters will be taken only once and not common characters will be taken as it is (string1's common character then string2's common character).

// length of supersequence = length of string1 + length of string2 - length of longest common subsequence.



// Approach (Using Tabulation) using the dp table

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
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
                if(str1[i-1]==str2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                // if it does not matches, then we will take the max of the 2 possibilities
                // 1. we will move to the next character of text1
                // 2. we will move to the next character of text2
                else
                    dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]); // basically its 0 + max(...)        
            }
        }


        // now we will find the supersequence
        string ans="";
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            // as the characters don't match then this means that
            // it has formed either from upper block or left block from the dp table
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans.push_back(str1[i-1]);
                    i--;
                }
                else{
                    ans.push_back(str2[j-1]);
                    j--;
                }
            }
        }

        // now we will add the remaining characters
        while(i>0){
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(str2[j-1]);
            j--;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};