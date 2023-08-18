// Similar to the maximum sum of non adjacent elements problem
// Just here we are having 2 cases, either picking 1st or last element
// and then calculating the rest array's maximum sum

class Solution {
public:
    long long int solve(vector<int>& arr){
        int n = arr.size();
        long long int prev = arr[0];
        long long int prev2 =0; // intially arr[-1] is 0 
        
        for(int i=1; i<n; i++){
            // // to pick (pick current and not pick next one)
            // long long int pick = arr[i];
            // // only if i > 1 then only add prev2, otherwise for negative its 0 only
            // if(i>1)
            //     pick += prev2;
            long long int pick = arr[i] + prev2; // same as above 3 lines
            
            // to not pick (not pick and then pick next one)
            long long int nonPick = 0 + prev;
            
            long long int cur_i = max(pick, nonPick);
            prev2 = prev;
            prev= cur_i;
            
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1;
        vector<int> arr2;
        
        if(n==1)
        return nums[0];
        
        for(int i=0; i<n; i++){
            // for array excluding 1st one
            if(i!=0) arr1.push_back(nums[i]);
            // for array excluding last one
            if(i!=n-1) arr2.push_back(nums[i]);
        }
        
        long long int ans1 = solve(arr1);
        long long int ans2 = solve(arr2);
    
        // returns the best of both the cases
        return max(ans1,ans2);
    }
};