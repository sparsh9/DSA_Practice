class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs; // Vector to store all subsets
        vector<int> sub; // Vector to store the current subset
        
        subsets(nums, 0, sub, subs); // Call the recursive helper function to generate subsets
        
        return subs; // Return the generated subsets
    }
    
private:
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub); // Add the current subset to the list of subsets
        
        // Generate subsets by including each element starting from index 'i'
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]); // Include the current element in the subset
            subsets(nums, j + 1, sub, subs); // Recursively generate subsets with the next index
            sub.pop_back(); // Backtrack by removing the last element to explore other possibilities
        }
    }
};
