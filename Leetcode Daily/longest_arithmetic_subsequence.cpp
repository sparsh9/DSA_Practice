class Solution {
public:
    int longestArithSeqLength(vector<int>& nums)
    {
        int n = nums.size(), ans = 0;
        vector<unordered_map<int, int>>mp(n);
        for (int i = n - 1; i >= 0; i--)
        {
            //if we go from (j = 0 to i) then we have to take "mp[i][diff] = max(mp[i][diff], 1 + x)"
            //as there might me be case of same start and same diff but "diff" j's
            //so j = n - 1 would have less length than j < n -1
            for (int j = n - 1; j > i; j--)
            {
                int diff = nums[j] - nums[i];
                int nextLen;
                if (!mp[j].count(diff)) nextLen = 1;
                else nextLen = mp[j][diff];
                
                //overriding if {i, diff} pair is same as smaller j will have greater len always
                mp[i][diff] = 1 + nextLen; 
                ans = max(ans, 1 + nextLen);
            }
        }
        return ans;
    }
};