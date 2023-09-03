/*
1) Here we can see that [1,6] and [2,8] overlap because starting of [2,8] is less than ending of [1,6]. In such cases 1 arrow will burst them both.
2) But if we check [1,6] and [7,12], they do not overlap because starting of [7,12] is not less than ending of [1,6]. In such cases, another arrow will be needed to burst it.
3) We will just apply this logic in our solution.
*/

class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)
            return 0;
        
        sort(points.begin(), points.end(), comp);
        
        int arrows = 1;
        int last = points[0][1];
        
        for(int i=1; i<points.size(); i++)
        {
            if(points[i][0]>last)
            {
                arrows++;
                last = points[i][1];
            }
        }
        return arrows;
    }
};
