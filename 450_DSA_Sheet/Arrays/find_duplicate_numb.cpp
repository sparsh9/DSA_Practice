// Approach 1 (using Binary Search)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            
            // count the number of elements smaller/ equal than middle element
            int c = 0;
            for(auto el: nums)
                if(el <= mid)
                    c++;
            
            if(c > mid)
                right = mid;
            else
                left = mid + 1;
        }
        return left; 
    }
};

// Approach 2 Slow and fast pointer approach
// Time complexity O(N)
// space complexity O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     int slow=nums[0],fast=nums[0];
     do
     {
         fast=nums[nums[fast]];
         slow=nums[slow];
     }while(slow!=fast);
     fast=nums[0];
        while(slow!=fast)
        {
            fast=nums[fast];
            slow=nums[slow];
        }
        return slow;
    }
};
