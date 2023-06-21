// Approach 1 (Using the monotonic decreasing-increasing function)
// Here we are finding the lowest value of the function where the cost is least and
// we make a imaginary new array where there will Sum(cost array) times elements and the elements will be the num[i]*cost[i] will be repeated
// final number to which it is to be converted is the median of all the elements of the final new array
class Solution {
public:

    long long calc(vector<int>&nums, vector<int>& cost, long long finalNumber){

        long long ans = 0;

         for(int i=0;i<nums.size();i++)
           ans += abs(1ll*nums[i]-finalNumber)*(1ll*cost[i]);

         return ans;  
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {

        long long tot = 0;
        long long sum = 0;
        int n = nums.size();

        vector<pair<int,int>> vec;

        for(int i=0;i<nums.size();i++)
            vec.push_back({nums[i],cost[i]});

        sort(vec.begin(),vec.end());

        for(int i=0;i<n;i++)
        sum += vec[i].second;

        long long median;
        int i=0;

        while(tot < (sum+1)/2 && i<n){

             tot += 1ll*vec[i].second;
             median = vec[i].first;
             i++;
        }    
        
        
        return calc(nums,cost,median);
    }
};