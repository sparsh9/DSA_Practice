class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for(int index=0;index<nums.size();index++)
        {
            if(index%10==nums[index])
                return index;
        }
        return -1;
    }
};