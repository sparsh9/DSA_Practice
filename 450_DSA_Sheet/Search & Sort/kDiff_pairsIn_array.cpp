class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int x: nums) m[x]++;
        int ans=0;
        // if k = 0 , it means there should be a number more than 1 times so that (num-num)=0
        if(k==0)
        {
            for(auto x: m) if(x.second>1) ans++;
        }
        // otherwise there should exist a number which is num+k in the map
        else
        {
            for(auto x: m)
            {
                if(m.count(x.first + k) > 0) ans++; 
            }
        }
        return ans;
    }
};