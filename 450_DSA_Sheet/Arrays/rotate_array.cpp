
// Approach (Mathematical and logical)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
             
        //in-place 
        k = k%nums.size();
        // reverse(a[0],a[n]) reverses all elements from a[0] to a[n-1]. It is [0,n) where n is not considered.
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