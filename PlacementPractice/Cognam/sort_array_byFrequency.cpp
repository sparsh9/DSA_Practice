class Solution {
public:
    // compares on basis of lower value pair
    static bool cmp(pair<int,int>&a, pair<int,int>&b) {
        return  (a.second==b.second) ? a.first>b.first : a.second<b.second;
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        if(nums.size()==1) 
            return nums;
        
        // counts and saves frequency
        map<int,int> mp;
        for(int i=0;i<nums.size();i++) 
        {
            mp[nums[i]]++;
        }

        // stores int,freq of int in form of vector
        vector<pair<int,int>> val_freq;
        for(auto m : mp) 
        {
            val_freq.push_back(m);
        }
        // sort accn to smaller frequencies
        sort(val_freq.begin(),val_freq.end(),cmp);

        // put int with less freq in starting
        vector<int> result;
        for(auto v : val_freq) {
            for(int i=0;i<v.second;i++) {
                result.push_back(v.first);
            }
        }
        return result;
    }
};