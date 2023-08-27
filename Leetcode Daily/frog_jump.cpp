// Approach : Recursion

class Solution {
public:
    // ind index se aage tak possible hai ya nahi 
    // and where k steps liye the pichle wale step mein
    bool helper(int ind, int k, vector<int>&s){
        // base case
        if(ind > s.size()-1)
            return false;

        if(ind == s.size()-1)
            return true;

        bool possible = false;

        // perform on steps
        for(int i = ind+1;i<s.size();i++){
            // maximum possible se zyada ho toh
            if(s[i] > s[ind]+k+1)
                break;
            
            // agar K+1 steps possible hai 
            else if(s[i] == s[ind] + k+1)
                possible |= helper(i,k+1,s);

            // agar k steps possible hai toh
            else if(s[i] == s[ind]+k)
                possible |= helper(i,k,s);
            
            // agar k-1 steps possible hai toh
            else if(s[i] == s[ind]+k-1 && k-1 > 0)
                possible |= helper(i,k-1,s);
        }

        return possible;
    }


    bool canCross(vector<int>& stones) {
        return helper(0,0,stones);
        // even though it is assumed that first step is of 1 steps,
        // but considering to be of 0 steps as k = 0 not possible so it will go with k+1 steps itself for this
    }
};




// Approach : Recursion + Memoization

class Solution {
public:
    // ind index se aage tak possible hai ya nahi 
    // and where k steps liye the pichle wale step mein
    bool helper(int ind, int k, vector<int>&s, vector<vector<int>>&dp){
        // base case
        if(ind > s.size()-1)
            return false;

        if(ind == s.size()-1)
            return true;

        // if already calculated
        if(dp[ind][k] != -1)
            return dp[ind][k];

        bool possible = false;

        // perform on steps
        for(int i = ind+1;i<s.size();i++){
            // maximum possible se zyada ho toh
            if(s[i] > s[ind]+k+1)
                break;
            
            // agar K+1 steps possible hai 
            else if(s[i] == s[ind] + k+1)
                possible |= helper(i,k+1,s,dp);

            // agar k steps possible hai toh
            else if(s[i] == s[ind]+k)
                possible |= helper(i,k,s,dp);
            
            // agar k-1 steps possible hai toh
            else if(s[i] == s[ind]+k-1 && k-1 > 0)
                possible |= helper(i,k-1,s,dp);
        }

        return dp[ind][k] = possible;
    }   

    bool canCross(vector<int>& stones) {
        vector<vector<int>>dp(stones.size(),vector<int>(stones.size(),-1));
        return helper(0,0,stones,dp);
        // even though it is assumed that first step is of 1 steps,
        // but considering to be of 0 steps as k = 0 not possible so it will go with k+1 steps itself for this
    }
};



// Approach : Tabulation


class Solution {
public:  
    bool canCross(vector<int>& stones) {
        int n = stones.size();
    
        
        vector<vector<int>> dp(stones.size(),vector<int>(stones.size(),true));

        // if first step is not 1
        if(stones[1] - stones[0] != 1)
            return false;

    }
};