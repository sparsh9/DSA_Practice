class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if(nums.size()<2)return true;
        int i,n = nums.size(),mx=0;
        for(i = 0; i < n-1; i++){
            if(mx==i&&nums[i]==0){
                return false;
            }
            mx = max(mx,i+nums[i]);
        }
        return mx>=i-1;
    }
};