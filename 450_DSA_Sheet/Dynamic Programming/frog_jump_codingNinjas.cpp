// Approach 1 (Using DP Memoization)
#include <bits/stdc++.h> 
 
int minen(int n , vector<int> &heights, vector<int> &dp){
    if( n == 0) return 0;
    
    if(dp[n] != -1) return dp[n];
    int right = INT_MAX; // INT_MAX is used because we are taking min of left and right
    // height[i] is for (i+1)th index (0 based indexing) 
    // and energy from ith to jth = height[i-1] = height[j-1]
    int left = minen(n-1 , heights, dp)+ abs(heights[n] - heights[n-1]);
    if (n > 1) {
      right = minen(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
    }
 
    return dp[n]= min(left ,right );
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1, -1);
    // we used n+1 because we are using 1 based indexing in dp as 
    // height[i] is for (i+1)th index (0 based indexing)
   return minen(n-1 , heights , dp);
 
}




// Approach 2 (Using DP Tabulation)
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Tabulation method
    vector<int> dp(n , 0);
    
    for(int i =1;  i <n; i++){
      int fs  = dp[i-1] + abs(heights[i] - heights[i-1]);
      int ss = INT_MAX;
      // second step will only happen if i is greater than 1 otherwise it will 
      // only take 1 step instead of 2
      if(i >1) ss= dp[i-2] + abs(heights[i] - heights[i-2]);
 
      dp[i] = min(fs,ss);
    }
    return dp[n-1];
}



// Approach 3 Best One (Space Optimization)
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
  // Best optimal Approach
  if(n ==0 ) return 0;
  int prev = 0;
  int prev2;
  for(int i=1; i< n; i++){
    int fs = prev + abs(heights[i] - heights[i-1]);
    int ss = INT_MAX;
    // second step will only happen if i is greater than 1 otherwise it will 
    // only take 1 step instead of 2
    if(i >1) ss = prev2 + abs(heights[i] - heights[i-2]);
    prev2= prev;
    prev = min(fs,ss);
  }
  return prev;
}