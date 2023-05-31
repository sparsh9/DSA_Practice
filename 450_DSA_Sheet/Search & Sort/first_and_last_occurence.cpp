// Approach 1 using 2 different Binary Searches for first and last occurences
// As soon as we find an occurence, we assume to find another one in left halves and right halves.
// So in the first occurence, we tend to find in left half as if there is any other and 
// in the last occurence, we tend to find in the right half as if there is any other
// This way we get both the positions
// Incase, if there is only one element it will return same answer,
// Otherwise it will return 2 different answers
class Solution {
int firstOcc(vector<int>& nums,int target){
    int s = 0;
    int e = nums.size()-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(nums[mid] == target){
            ans = mid;
            e = mid-1;
        }
        else if(target < nums[mid]){
            e = mid-1;
        }
        else if(target > nums[mid]){
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
int lastOcc(vector<int>& nums,int target){
    int s = 0;
    int e = nums.size()-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(nums[mid] == target){
            ans = mid;
            s = mid+1;
        }
        else if(target < nums[mid]){
            e = mid-1;
        }
        else if(target > nums[mid]){
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(firstOcc(nums,target));
        ans.push_back(lastOcc(nums,target));
        return ans;
    }
};