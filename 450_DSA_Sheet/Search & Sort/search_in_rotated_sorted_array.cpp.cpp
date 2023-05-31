// Method 1

class Solution {
    int findPivot(vector<int>& nums){
        int s=0,e=nums.size()-1;
        int mid = s+(e-s)/2;
        while(s<e){
            if(nums[mid]>=nums[0])
                s=mid+1;
            else
                e=mid;
            
        mid = s+(e-s)/2;
        }
        return s;
    }
    int binarySearch(vector<int>& nums, int target,int st,int en){
        int mid = st+(en-st)/2;
        while(st<=en){
            if(nums[mid] == target)
                return mid;
            else if(target>nums[mid])
                st=mid+1;
            else
                en=mid-1;
            mid = st+(en-st)/2;
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        int pivot = findPivot(nums);
        if(target >= nums[pivot] && target <= nums[e])
            return binarySearch(nums,target,pivot,e);
        else
            return binarySearch(nums,target,0,pivot-1);
    }
};

// Method 2
// Given Array must be sorted on either side of the nums[mid], therefore we are checking for both the cases where it is
// when we get the side where it is sorted
// then we check if the target lies in that region or not
// If the target lies in that region, then eventually after iterations, its mid will come to the targets index and then we will return it
// Otherwise if the target does not lie in that region, we will immediately switch to other side, even though if it is not sorted
// If neither cases follow or if after several iterations, the mid does not reach target's idex, we simply return -1.
// This way we are reducing our search space using the binary search
class Solution {
public:
    int search(vector<int>& nums, int target) {
     int n = nums.size();
      int left = 0;
      int right = n-1;
      int mid= left + (right - left) / 2;
      while(left <= right){
        if(nums[mid] == target)
         return mid;
        if(nums[mid] >= nums[left]) {
          if(target >= nums[left] && target <= nums[mid])
            {
                right = mid - 1;
            }
           else left = mid + 1;
        } 
        else {
          if(target >= nums[mid] && target <= nums[right]) 
            left = mid + 1;
          else right = mid - 1;
        }
          mid = left + (right - left) / 2;
      }
      return -1;
    }
};
