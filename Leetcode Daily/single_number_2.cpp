// Approach 1(Using maps)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for(auto x: nums){
            m[x]++;
        }

        for(auto x: m){
            if(x.second == 1){
                return x.first;
            }
        }
        
        return -1;
    }
};

// Approach 2(Using linear traversal from index 1 at a step of 3)  T.C = O(32*N) for only worst case
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n=nums.size();
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n - 1] != nums[n - 2]) return nums[n - 1];
        for(int i = 1 ; i < n ; i += 3){
            if(nums[i] != nums[i -1 ]) return nums[i - 1];
        }
        return -1;
    }
};
// Approach 3(Using Counting Set Bits) T.C = O(32*N) for all cases
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0 ; i < 32 ; i++){
            int cntodd = 0;
            for(auto it: nums){
                if((1 << i) & it) cntodd++;
            }
            if(cntodd % 3) ans = ans | (1 << i);
        }
        return ans;
    }
};

// Approach 4 (bit manipulation)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Initialize two variables: 'ones' and 'twos' to keep track of the bit counts
        int ones = 0, twos = 0;
        
        // Iterate through each element in the 'nums' vector
        for(auto it: nums){
            // Update 'ones' by performing XOR operation between 'ones' and the current element,
            // and then performing AND operation with the complement of 'twos'.
            // This ensures that the bits set in 'ones' are not present in 'twos'.
            ones = (ones ^ it) & (~twos);
            
            // Update 'twos' by performing XOR operation between 'twos' and the current element,
            // and then performing AND operation with the complement of 'ones'.
            // This ensures that the bits set in 'twos' are not present in 'ones'.
            twos = (twos ^ it) & (~ones);
        }
        
        // The single number will be stored in 'ones' after the iteration completes,
        // since 'ones' keeps track of the bits that appear once.
        return ones;
    }
};

