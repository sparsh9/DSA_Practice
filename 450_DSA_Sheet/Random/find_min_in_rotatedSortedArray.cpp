class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,n=nums.size();
        int e = n-1;

        while(s < e){
            int m = s + (e-s)/2;
            // agar left ke elements bade hai toh
            if(nums[m] > nums[e]) 
                s = m+1;
            // agar right elements bade hai toh
            else if(nums[m] < nums[e])
                e = m;
            // agar mid value hi equal hai
            else 
                e--;                
        }
        return nums[s];
    }
};