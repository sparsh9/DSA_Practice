class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        // here we are using the property of XOR that a^a = 0
        // so we are XORing all the elements of the array and the index of the array
        // and then we are XORing the result with the size of the array
        for(int i=0; i<nums.size(); i++){
            res ^= i;
            res ^= nums[i];
        }
        res^= nums.size();
        return res;
    }
};