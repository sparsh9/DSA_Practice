class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            res ^= i;
            res ^= nums[i];
        }
        res^= nums.size(); // Because we were intially running loop till second last element (for ith case) and we have to take the last element as well (which is i = n)
        return res;
    }
};