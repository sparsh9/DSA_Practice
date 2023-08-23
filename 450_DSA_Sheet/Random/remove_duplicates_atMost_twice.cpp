// Remove Duplicates from Sorted Array where each element can be repeated at most twice
// Therefore we check for the element at i-2 and if the element is not equal to it then we simply replace the element at i with the current element
// This is because we can have at most 2 duplicates

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; // i is the index of the next element to be replaced
        for(auto e : nums) {
            if(i < 2 || e > nums[i-2]) {
                nums[i] = e;
                i++;
            }
        }
        return i;
    }
};