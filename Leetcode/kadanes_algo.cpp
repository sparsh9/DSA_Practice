// Approach 1 (Using Kadanes Algorithm)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // max_sum_till is the maximum sum so far till now.
        // max_sum_current is the maximum sum till the current index
        int max_sum_till = INT_MIN;
        int max_sum_current = 0;
        for(auto it : nums){
            max_sum_current+=it;
            if(max_sum_till<max_sum_current) max_sum_till = max_sum_current;
            if(max_sum_current<0) max_sum_current=0;
        }
        return max_sum_till;
    }
};