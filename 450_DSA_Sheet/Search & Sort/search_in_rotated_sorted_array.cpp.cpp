// Method 1 (Brute Force)
class Solution {
    // Function to find the pivot element in the rotated sorted array
    int findPivot(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end - start) / 2;

        while (start < end) {
            if (nums[mid] >= nums[0])
                start = mid + 1;
            else
                end = mid;

            mid = start + (end - start) / 2;
        }
        return start;
    }

    // Binary search function to find the target element in the array
    int binarySearch(vector<int>& nums, int target, int start, int end) {
        int mid = start + (end - start) / 2;

        while (start <= end) {
            if (nums[mid] == target)
                return mid;
            else if (target > nums[mid])
                start = mid + 1;
            else
                end = mid - 1;

            mid = start + (end - start) / 2;
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        // Find the pivot element (smallest element) in the rotated sorted array
        int pivot = findPivot(nums);

        // If the target lies between pivot and last element, perform binary search on that segment
        if (target >= nums[pivot] && target <= nums[end])
            return binarySearch(nums, target, pivot, end);
        // Otherwise, perform binary search on the segment before pivot
        else
            return binarySearch(nums, target, start, pivot - 1);
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
        int right = n - 1;
        int mid = left + (right - left) / 2;

        // Binary search loop
        while (left <= right) {
            // If the target is found at mid, return the index
            if (nums[mid] == target)
                return mid;

            // Check if the left segment is sorted
            if (nums[mid] >= nums[left]) {
                // Check if the target lies within the left segment
                if (target >= nums[left] && target <= nums[mid]) {
                    right = mid - 1; // Update the right pointer to search in the left segment
                } else {
                    left = mid + 1; // Update the left pointer to search in the right segment
                }
            } 
            // If the right segment is sorted
            else {
                // Check if the target lies within the right segment
                if (target >= nums[mid] && target <= nums[right]) {
                    left = mid + 1; // Update the left pointer to search in the right segment
                } else {
                    right = mid - 1; // Update the right pointer to search in the left segment
                }
            }
            // Calculate the new mid after updating the pointers
            mid = left + (right - left) / 2;
        }

        return -1; // If target is not found, return -1
    }
};

