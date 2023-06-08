// Approach 1 (using 2 pointers)
class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }

        int count = 0;
        int left = 0;
        int right = 1;

        while (right < n - 1) {
            if (nums[right + 1] - nums[right] == nums[right] - nums[right - 1]) {
                // The current three elements form an arithmetic slice.
                count += right - left;
                right++;
            } else {
                // Reset the pointers to find the next arithmetic slice.
                left = right;
                right++;
            }
        }

        return count;
    }
};

