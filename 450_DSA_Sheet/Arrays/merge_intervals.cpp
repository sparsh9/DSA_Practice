// Approach 1 (using sorting and storing)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1)
            return intervals;

        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(auto interval : intervals){
            // If intervals are overlapping
            if(ans.back()[1] >= interval[0])
                ans.back()[1] = max(interval[1] , ans.back()[1]);
            // If they are not overlapping
            else
                ans.push_back(interval);
        }
        return ans;
    }
};