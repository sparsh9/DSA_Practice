//Approach-1 (Using Prefix Array)
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(k == 0)
            return nums;
    
        vector<int> result(n, -1);
        
        if(n < 2*k + 1)
            return result;
        
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        // Storing the sums of prefix 
        for(int i = 1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
            
        }

        for(int i = k; i<n-k; i++) {
            
            int left_idx  = i-k;
            int right_idx = i+k;
            
            long long sum = prefixSum[right_idx];

            // checking if the left_idx is greater than 0 otherwise it will be in negative
            if(left_idx > 0)
                sum -= prefixSum[left_idx-1];
            
            // taking the average values
            int avg = sum/(2*k+1);
            result[i] = avg;  
        }
        
        return result;
        
    }
};


// Approach 2 (Using Sliding Window)
