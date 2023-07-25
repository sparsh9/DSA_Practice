// It utilises the concept of subset sum equal to target problem
// now we know that the last row of the dp[index][target] signifies whether we can make the target or not for the given index(last index = array size)
// so we get that for an array size, what are the possible targets that we can make using subsets of the array
// therefore we have one subset of sum equal to this one of the possible targets
// and other subset will be subset2 = total array sum - subset1

// hence we can run a for loop to minimize the difference between the two subsets using mini = INT_MAX concept


class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;

        for (int i = 0; i < n; i++) {
            totSum += nums[i];
        }

        int half = n / 2;
        vector<int> subset1, subset2;
        int mini = INT_MAX;

        // Generate all possible subset sums for the first half of the array
        for (int mask = 0; mask < (1 << half); mask++) {
            int sum = 0;
            for (int i = 0; i < half; i++) {
                if (mask & (1 << i)) {
                    sum += nums[i];
                }
            }
            subset1.push_back(sum);
        }

        // Generate all possible subset sums for the second half of the array
        for (int mask = 0; mask < (1 << (n - half)); mask++) {
            int sum = 0;
            for (int i = half; i < n; i++) {
                if (mask & (1 << (i - half))) {
                    sum += nums[i];
                }
            }
            subset2.push_back(sum);
        }

        // Sort the second subset in ascending order
        sort(subset2.begin(), subset2.end());

        // Find the minimum difference between subset sums
        for (int sum : subset1) {
            auto it = lower_bound(subset2.begin(), subset2.end(), totSum - sum);
            if (it != subset2.end()) {
                int diff = abs(totSum - 2 * sum);
                mini = min(mini, diff);
            }
            if (it != subset2.begin()) {
                it--;
                int diff = abs(totSum - 2 * sum + 2 * (*it));
                mini = min(mini, diff);
            }
        }

        return mini;
    }
};

