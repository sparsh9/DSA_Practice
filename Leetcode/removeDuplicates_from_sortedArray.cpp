// Approach 1 using 2 pointers
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        if(n<2)
            return n;
        // Initially there will be atleast 1 unique element hence ans = 1 
        int ans=1, left=0;
        // it will move till last element
        for(int right=1; right<n; right++){
            if(nums[right]!=nums[left]){
                left++;
                nums[left]=nums[right];
                ans++;
            }
        }
        return ans;
    }
};