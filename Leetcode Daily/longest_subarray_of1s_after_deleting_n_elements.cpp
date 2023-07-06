// Approach-1: Simple Brute Force
// Time Complexity: O(n^2)

class Solution {
public:
    int n; // Variable to store the size of the input array
    
    // Function to find the maximum length of consecutive ones in the array, excluding the element at 'skip_idx'
    int findMax(vector<int>& nums, int skip_idx) {
        int currLength = 0; // Current length of consecutive ones
        int maxLength  = 0; // Maximum length of consecutive ones
        
        // Iterate through the array
        for (int i = 0; i < n; i++) {
            if (i == skip_idx)
                continue; // Skip the element at 'skip_idx'
            
            if (nums[i] == 1) {
                currLength++; // Increment the current length of consecutive ones
                maxLength = max(maxLength, currLength); // Update the maximum length if necessary
            } else {
                currLength = 0; // Reset the current length if the current element is not 1
            }
        }
        
        return maxLength; // Return the maximum length of consecutive ones
    }
    
    int longestSubarray(vector<int>& nums) {
        n = nums.size(); // Store the size of the input array
        int result = 0; // Variable to store the final result
        
        int countZero = 0; // Count of zeros in the array
        
        // Iterate through the array to count zeros and find the maximum length of consecutive ones
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                countZero++; // Increment the count of zeros
                result = max(result, findMax(nums, i)); // Update the result by finding the maximum length of consecutive ones excluding the current zero
            }
        }
        
        if (countZero == 0)
            return n - 1; // If there are no zeros in the array, return the size of the array - 1 as the result
        
        return result; // Return the maximum length of consecutive ones after excluding each zero
    }
};

// Approach 2: Sliding Window
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount = 0; // Count of zeros encountered
        int longestWindow = 0; // Length of the longest subarray
        
        int i = 0; // Start index of the sliding window
        
        for (int j = 0; j < nums.size(); j++) {
            zeroCount += (nums[j] == 0); // Increment zeroCount if the current element is zero
            
            // Shrink the window until the zero count comes under the limit (one zero allowed)
            while (zeroCount > 1) {
                zeroCount -= (nums[i] == 0); // Decrement zeroCount if the element at the start of the window is zero
                i++; // Move the start index of the window forward
            }
            
            longestWindow = max(longestWindow, j - i); // Update the longestWindow length
            
        }

        return longestWindow;
    }
};

// Approach 3 : (More Better Optimal using sliding window)
// Time Complexity: O(n)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0; // Start index of the sliding window
        int j = 0; // End index of the sliding window
        
        int last_zero_idx = -1; // Index of the last zero encountered
        
        int result = 0; // Length of the longest subarray
        
        while (j < nums.size()) {
            if (nums[j] == 0) {
                i = last_zero_idx + 1; // Move the start index of the window to the right of the last zero
                last_zero_idx = j; // Update the last zero index to the current index
            }
            
            result = max(result, j - i); // Update the longest subarray length
            
            j++; // Move the end index of the window forward
        }
        
        return result;
    }
};

