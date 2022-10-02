// Approach 1 (Kadane's Algorithm)
// Intution : We carry a subarray sum as long as it gives us the +ve sum
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxi = INT_MIN;
       int sum = 0;
       for(auto it : nums){
        sum += it;
        maxi = max(maxi,sum);
        if(sum < 0) sum = 0;
       }
       return maxi;    
    }
};

// Approach 2 (using 2 for loops)

// 1) 1st Iterator for all iterators in the nums.
// 2) 2nd Iterator with respect to the 1st iterator and increasing the sum for each iteration.
// 3) Checking the maximum sum and returning it.
// 4) O(n2) time complexity.



// Approach 3 (optimal to Approach 2)
// 1) using Stack Data structure and using only 1 iteration.