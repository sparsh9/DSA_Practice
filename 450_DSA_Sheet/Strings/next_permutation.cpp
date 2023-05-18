// Approach 1 using simple mathematical logic
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1; // index to locate where the decrement starts
        int n = nums.size();
        
        // Find the index where the decrement starts
        // here we took i>0 and not i>=0 bcz i-1 at 0 would be negative and therefore to avoid this
        // we instead check the previous number in the condition and take the i-1 as we want the index
        // right from where the decrement of numbers start
        for(int i = n - 1; i > 0; i--){
            if(nums[i] > nums[i - 1]){
                idx = i - 1;
                break;
            }        
        }
        
        // If no decrement found, reverse the entire vector
        if(idx == -1){
            reverse(nums.begin(), nums.end());
        }
        else{
            // Here we will start to find from elements afer nums[idx] therefore idx+1
            int prev = idx + 1;
            
            // Find the index of the next closest greater element
            for(int i = idx + 2; i < n; i++){
                // Here we will be updating the prev index everytime
                // we find a next closest value which meets the condition
                if(nums[i] > nums[idx] && nums[i] <= nums[prev])
                    prev = i;
            }
            
            // Swap the elements
            swap(nums[idx], nums[prev]);
            
            // Reverse the suffix starting from idx + 1
            reverse(nums.begin() + idx + 1, nums.end());
        }
    }
};
