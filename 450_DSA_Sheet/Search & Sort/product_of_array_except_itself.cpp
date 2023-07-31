class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input vector nums.

        // Create two arrays: fromBegin and fromLast, to store the product of elements from the beginning and end.
        vector<int> fromBegin(n);
        vector<int> fromLast(n);

        // Initialize the first element of fromBegin to 1.
        fromBegin[0] = 1;

        // Initialize the last element of fromLast to 1.
        fromLast[n - 1] = 1;

        // Calculate the product of elements from the beginning and store it in the fromBegin array.
        for (int i = 1; i < n; i++) {
            fromBegin[i] = fromBegin[i - 1] * nums[i - 1];
        }

        // Calculate the product of elements from the end and store it in the fromLast array.
        for (int i = n - 2; i >= 0; i--) {
            fromLast[i] = fromLast[i + 1] * nums[i + 1];
        }

        // Calculate the final result array by multiplying elements from fromBegin and fromLast arrays for each index.
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = fromBegin[i] * fromLast[i];
        }

        // Return the final result array.
        return res;
    }
};
