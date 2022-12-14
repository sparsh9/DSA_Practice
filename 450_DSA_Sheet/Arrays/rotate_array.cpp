
// Approach (Mathematical and logical)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
             
        //in-place 
        k = k%nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

// Approach (Using extra space)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        for(int i=0; i<n; i++){
            temp[(i+k)%n] = nums[i];
        }
        nums = temp;
    }
};