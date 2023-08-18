// This problem can be solved using the subset partition with given difference problem
// Here we have to find the number of subsets with given difference
// such that (sum of subset1 - sum of subset2) = target
// as the subset2 can be considered as all the elements with negative sign 
// and subset1 can be considered as all the elements with positive sign
// so the above equation can be written as 
// (sum of subset1 - sum of subset2) = target



// Approach (Using Memoization)

class Solution {
public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        // target sum is (sum-d)/2 
        int tar=(sum-d)/2;
        // checking if the target sum is possible or not and if it is divisible by 2 or not
        if((sum-d)%2!=0 || (sum-d)<0) return 0;


        vector<vector<int>>dp(n,vector<int>(tar+1,0));

        // base case : if the first element is 0 then we can take it as positive or negative, otherwise we can take it as positive only
        if(arr[0]==0)
            dp[0][0]=2;
        else
            dp[0][0]=1;

        // base case : if the first element is not 0 and it is less than or equal to target
        if(arr[0]!=0 && arr[0]<=tar){
            dp[0][arr[0]]=1;
        }

        for(int i=1;i<n;i++){
            for(int k=0;k<=tar;k++){
                // here np is the number of partitions without taking the current element
                int np=dp[i-1][k];
                // here p is the number of partitions with taking the current element
                int p=0;
                if(arr[i]<=k) // if the current element is less than or equal to target
                    p=dp[i-1][k-arr[i]];
                
                dp[i][k]=(p+np);
            }
        }
        
        return dp[n-1][tar];
        
    }
    int findTargetSumWays(vector<int>& arr, int target) {
        int n=arr.size();
        return countPartitions(n,target,arr);
    }
};