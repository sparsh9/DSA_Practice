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

