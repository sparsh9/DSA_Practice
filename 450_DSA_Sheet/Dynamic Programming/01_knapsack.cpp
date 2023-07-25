//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int helper(int n,int W,int wt[],int val[],vector<vector<int>>& dp){
        if(n==0 || W==0){
            return 0;
        }
        if(dp[n][W]!=0){
            return dp[n][W];
        }
        if(wt[n-1]<=W){
            return dp[n][W] = max(val[n-1]+helper(n-1,W-wt[n-1],wt,val,dp),helper(n-1,W,wt,val,dp));
        }
        else{
            return dp[n][W] = helper(n-1,W,wt,val,dp);
        }
    }


    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n+1,vector<int>(W+1,0));
       return helper(n,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends