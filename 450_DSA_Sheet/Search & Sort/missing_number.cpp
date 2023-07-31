// x ^ x = 0 or simply x xor x gives 0
// so here we are XORing all the indices and all the elements in the array
// so the only element left will be the missing number as it was not there in the array and hence it remains

int missingNumber(vector<int>& nums) {
    int res = 0;
    // XOR all the indices (0 to n-1) and all the elements in the array
    for (int i = 0; i < nums.size(); i++) {
        res ^= i;
        res ^= nums[i];
    }
    // XOR the last element (n) to find the missing number
    // Because we were intially running loop till second last element (for ith case) 
        // and we have to take the last element as well (which is i = n)
    res ^= nums.size();
    return res;
}
