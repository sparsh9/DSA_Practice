// Here we are using the string matching logic wherein in every step, we have 3 possibilities

// Approach 1 (Recursion)
class Solution {
public:

    int helper(int i, int j, string &word1, string &word2){
        // base case
        if(i < 0)
            return j+1;
        if(j < 0)
            return i+1;

        // if the characters match then we will move to the next character as no operation needed
        if(word1[i]==word2[j])
            return helper(i-1,j-1,word1,word2);

        // if the characters don't match then we will take the min of the 3 possibilities
        // 1. we will do insertion and assume that we have inserted the character before in word1 and therefore we will move to the next character of text2
        // 2. we will delete the character and assume that we have deleted the character from word1 and therefore we will move to the next character of text1
        // 3. we will replace the character and then we will move to the next character of both text1 and text2
        else{
            int text_insert = 1+helper(i,j-1,word1,word2);
            int text_delete = 1+helper(i-1,j,word1,word2);
            int text_replace = 1+helper(i-1,j-1,word1,word2);
            return min(text_insert,min(text_delete,text_replace));
        }
        
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        return helper(n-1,m-1,word1,word2);
    }
};



// Approach 2 (Recursion + Memoization)
class Solution {
public:

    int helper(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        // base case
        if(i < 0)
            return j+1;
        if(j < 0)
            return i+1;

        // if the characters match then we will move to the next character as no operation needed
        if(word1[i]==word2[j])
            return helper(i-1,j-1,word1,word2,dp);

        // if the characters don't match then we will take the min of the 3 possibilities
        // 1. we will do insertion and assume that we have inserted the character before in word1 and therefore we will move to the next character of text2
        // 2. we will delete the character and assume that we have deleted the character from word1 and therefore we will move to the next character of text1
        // 3. we will replace the character and then we will move to the next character of both text1 and text2
        else{
            if(dp[i][j]!=-1)
                return dp[i][j];
            int text_insert = 1+helper(i,j-1,word1,word2,dp);
            int text_delete = 1+helper(i-1,j,word1,word2,dp);
            int text_replace = 1+helper(i-1,j-1,word1,word2,dp);
            return dp[i][j]=min(text_insert,min(text_delete,text_replace));
        }
        
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return helper(n-1,m-1,word1,word2,dp);
    }
};


// Approach 2.2 (Recursion + Memoization) 1 based indexing
class Solution {
public:

    int helper(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        // base case
        if(i == 0)
            return j;
        if(j == 0)
            return i;

        // if the characters match then we will move to the next character as no operation needed
        if(word1[i-1]==word2[j-1])
            return helper(i-1,j-1,word1,word2,dp);

        // if the characters don't match then we will take the min of the 3 possibilities
        // 1. we will do insertion and assume that we have inserted the character before in word1 and therefore we will move to the next character of text2
        // 2. we will delete the character and assume that we have deleted the character from word1 and therefore we will move to the next character of text1
        // 3. we will replace the character and then we will move to the next character of both text1 and text2
        else{
            if(dp[i][j]!=-1)
                return dp[i][j];
            
            int text_insert = 1+helper(i,j-1,word1,word2,dp);
            int text_delete = 1+helper(i-1,j,word1,word2,dp);
            int text_replace = 1+helper(i-1,j-1,word1,word2,dp);
            return dp[i][j]=min(text_insert,min(text_delete,text_replace));
        }
        
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        return helper(n,m,word1,word2,dp);
    }
};



// Approach 3 (Tabulation)
class Solution {
public:

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        // base case : for indexes at 0, we will fill the dp array with 0
        for(int i=0;i<=n;i++)
            dp[i][0]=i;
        for(int j=0;j<=m;j++)
            dp[0][j]=j;
        
        // now we will fill the dp array
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                // it is 1 based indexing for dp vector, but 0 based for the char string for both wordss, 
                // therefore we check i-1,j-1 for words and update corresponding i,j values for dp vector array
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];

                // if it does not matches, then we will take the min of the 3 possibilities
                // 1. we will do insertion and assume that we have inserted the character before in word1 and therefore we will move to the next character of text2
                // 2. we will delete the character and assume that we have deleted the character from word1 and therefore we will move to the next character of text1
                // 3. we will replace the character and then we will move to the next character of both text1 and text2
                else
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));        
            }
        }
        return dp[n][m];
    }
};