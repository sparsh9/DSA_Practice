class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;
        
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        for(auto it:mp){
            if(it.second.size()>1){
                for(int i=0;i<it.second.size()-1;i++){
                    if(it.second[i+1]-it.second[i]<=k){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};



// Approach : More Better Approach

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
                mp[nums[i]]=i;
            }
            else
            {
                if(abs(i-mp[nums[i]])<=k)
                return true;
            }
            mp[nums[i]] = i;
        }
        return false;
        
    }
};