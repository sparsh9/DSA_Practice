/*
    Total 3 cases possible here :

1)  The new interval's range is before the range of current interval.
    Example new interval= {3,4} and current interval= {6,9}

2)  The new interval is after the range of current interval.
    Example new interval= {5,7} and current interval= {2,3}

3)  The new interval range overlaps with the range of current interval.
    Example interval= {5,9} and new interval= {6,11}

*/ 


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        for(int i=0;i<intervals.size();i++){
            //case 1 occurs
            if(intervals[i][0] > newInterval[1]){
                ans.push_back(newInterval);
                newInterval = intervals[i]; 
            }

            //case 2 occurs
            else if(intervals[i][1] < newInterval[0]){ans.push_back(intervals[i]);}       
    
            //case 3 occurs
            else if(intervals[i][1] >= newInterval[0] || intervals[i][0] <= newInterval[1]){
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        //final step
        ans.push_back(newInterval); 
        return ans;
    }
};