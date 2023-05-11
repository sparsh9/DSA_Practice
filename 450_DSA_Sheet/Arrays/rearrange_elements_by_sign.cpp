class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int positive = 0,negative = 1;
        vector<int> ans(n);
        for(auto num : nums){
            if(num > 0){
                ans[positive] = num;
                positive +=2;
            }
            else if(num < 0){
                ans[negative] = num;
                negative +=2;
            }
        }
        return ans;
    }
};