class Solution {
public:
    // Approach 1 using HashMaps
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     unordered_map<int,int> mp;
    //     vector<int> ans;
    //     for(int i=0;i<nums.size();i++){
    //         int sum = target - nums[i];
    //         if(mp.find(sum) != mp.end()){
    //             ans.push_back(mp[sum]);
    //             ans.push_back(i);
    //             return ans;
    //         }
    //         mp[nums[i]] = i;
    //     }
    //     return ans;
        
    // }

    // Approach 2
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        sort(nums.begin(),nums.end());
        while(l<r){
            int sum = nums[l]+nums[r];
            if(sum == target){}
            else if (sum > target)
                r--;
            else 
                l++;
        }
        ans.push_back(mp.find(nums[l])->second);
        ans.push_back(mp.find(nums[r])->second);
        return ans;
    }




};