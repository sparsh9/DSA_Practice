/*
Here first we are creating a map of unique numbers and instead of their frequencies,
we will store their sum. 

Note : the unordered_map is sorted therefore, we can use the same approach as house robber problem.

we are applying the indexes travel part in the map instead of the array.
Suppose if we pick an element from the array i.e. nums[i] then we can't pick nums[i-1] and nums[i+1]
Therefore we also can't pick the elements from the map which are adjacent to the current element.
Therefore index-2 will happen for next recursion call.
similarly, if we not pick then index-1 will happen for next recursion call.

*/

// // Approach (Recursion + Memoization)

// class Solution {
// public:
//     int f(int ind,vector<int>& sum,vector<int>& dp){   
//         // base case
//         if(ind==0) return sum[0];
//         if(ind<0) return 0;

//         // check if already calculated
//         if(dp[ind]!=-1) return dp[ind];

        
//         int pick=sum[ind]+f(ind-2,sum,dp);
//         int notpick=0+f(ind-1,sum,dp);
//         return dp[ind]=max(pick,notpick);
//     }
//     int deleteAndEarn(vector<int>& nums){
//         int n = 10001;
//         vector<int> sum(n, 0);
//         for(auto num: nums){
//             sum[num]+=num;
//         }
//         vector<int> dp(n, -1);
//         int m=sum.size();
//         return f(m-1,sum,dp);
//     }
// };



// Approach : Tabulation

class Solution {
public:
    int deleteAndEarn(vector<int>& nums){
        int n = 10001;
        vector<int> sum(n, 0);
        for(auto num: nums){
            sum[num]+=num;
        }
        vector<int> dp(n, -1);
        dp[0]=sum[0]; // till 0th index array, we don't option therefore we need to pick the 0th element
        dp[1]=max(sum[0],sum[1]); // here till 1st index, we either pick 0th or 1st element, 
        // but when we delete 0th element then 1st element gets deleted automatically therefore we need to pick the max of both. 
        for(int i=2;i<n;i++){
            int pick = sum[i]+dp[i-2];
            int notpick = dp[i-1];

            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
};