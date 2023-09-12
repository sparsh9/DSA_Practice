// Approach 2 (using 3-pointer)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            switch(nums[mid]){
                case 0 : swap(nums[mid++],nums[low++]);break;
                case 1 : mid++;break;
                case 2 : swap(nums[mid],nums[high--]);break;
            }

        }
        for(auto item:nums){
            cout<<item;
        }
    }
};