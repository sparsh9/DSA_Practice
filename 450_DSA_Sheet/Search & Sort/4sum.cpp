//Optimized Approach using two pointer - O(n^3) time and O(n) space
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> output;
        for (int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l) {
                    // Integer overflow error
                    // long long int sum = nums[i]+nums[j]+nums[k]+nums[l];
                    long long int sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum == target) {
                        s.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        for(auto quadruplets : s)
            output.push_back(quadruplets);
        return output;
    }
};


// More better optimal approach using 2 pointer and avoiding repeating some conditions
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> quadruplets;
        
        int n = nums.size();
        
        for (int i = 0; i < n - 3; i++) {
            // we skip the current iteration to avoid duplicate quadruplets starting with the same nums[i] value.
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate elements
            
            for (int j = i + 1; j < n - 2; j++) {
                // we skip the current iteration to avoid duplicate quadruplets starting with the same nums[i] and nums[j] values.
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicate elements
                
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    // long long int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    long long int sum = nums[i];
                    sum += nums[j];
                    sum += nums[left];
                    sum += nums[right];
                    
                    if (sum < target) {
                        left++;
                    } else if (sum > target) {
                        right--;
                    } else {
                        quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // They ensure that if the left or right pointer is at a duplicate element, we skip that element to avoid duplicate quadruplets.
                        while (left < right && nums[left] == nums[left + 1]) left++; // Skip duplicate elements
                        while (left < right && nums[right] == nums[right - 1]) right--; // Skip duplicate elements
                        
                        left++;
                        right--;
                    }
                }
            }
        }
        
        return quadruplets;
    }
};
