// Here main logic is that first we check if total sum of subset is an even number or not
// if its not even then we can't divide it into two equal subsets
// now if it is even, then we have to check if there is any subset whose sum is equal to total sum/2
// we then apply logic of finding subset sum equal to target


// Approach 1 (Using Recursion)

class Solution {
public:
    bool helper(int n, int k, vector<int> &arr) {
        if(k == 0) return true;
        if(n < 0) return false;
        if(arr[n] <= k) {
            bool take = helper(n-1,k-arr[n],arr); // target is reduced by arr[n]
            bool notTake = helper(n-1,k,arr); // target remains same
            return take || notTake;
        }
        return helper(n-1,k,arr);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto x : nums) sum += x;

        // if sum is odd, then we can't divide it into two equal subsets
        if(sum % 2 != 0) return false;

        return helper(n,sum/2,nums);
    }
};



// Approach 2 (Using Memoization) Top Down

class Solution {
public:
    bool solve(int index,int target,vector<int>&arr,vector<vector<int>>&dp){
        // base case
        if(target==0) return true;
        // last index
        if(index==0) return (arr[0]==target);

        // if already calculated
        if(dp[index][target]!=-1)return dp[index][target];

        bool nottake=solve(index-1,target,arr,dp);
        bool take = false;
        if(target >= arr[index])
            take = solve(index-1,target-arr[index],arr,dp);

        return dp[index][target]= take | nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0,k;
        if(n==1)return false;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        k=sum;
        if(sum%2!=0){
            return false;
        }
        else{
            sum=sum/2;
            if(nums.size()==1)return false;
            vector<vector<int>>dp(n,vector<int>(sum+1,-1));
            return solve(n-1,sum,nums,dp);
        }
    }
};


// Approach 3 (Using Tabulation) Bottom Up

class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for(auto &i : nums){
            sum += i;
        }

        // meaning we can't divid the array into two parts
        if(sum%2 != 0){
            return false;
        }
        int target = sum/2;

        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(target+1, 0));

        // base case
        for(int i = 0; i<n; i++){
            dp[i][0] = 1;
        } 

        // starting base case
        if(nums[0] <= target){
            dp[0][nums[0]] = 1;
        }

        for(int ind = 1; ind<n; ind++){
            for(int tar = 1; tar<=target; tar++){
                // not take  case
                bool notTake = dp[ind-1][tar];
                // take case
                bool take = 0;
                if(nums[ind] <= tar){
                    take = dp[ind-1][tar-nums[ind]];
                }
                dp[ind][tar] = take || notTake;
            }
        }

        return dp[n-1][target];
    }
};