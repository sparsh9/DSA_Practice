// Approach 1 (Using even odd sum concept)
// As no 2 houses can be robbed, therefore every adjacent houses will be summed differently
class Solution {
public:
    int rob(vector<int>& nums) {
        int even_sum = 0; // Sum of even-indexed elements
        int odd_sum = 0; // Sum of odd-indexed elements

        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                even_sum = max(even_sum + nums[i], odd_sum);
            } else {
                odd_sum = max(odd_sum + nums[i], even_sum);
            }
        }

        return max(even_sum, odd_sum);
    }
};