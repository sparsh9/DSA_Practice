// Approach 1 (using max heap)
// Similar to kth largest element in a stream question concept
// just see that
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // Initiating max heap instead of min heap to save memory
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                // below process will ensure that only k pairs are there in the heap till last 
                // and these will be the final answer at last
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k)pq.push({sum,{nums1[i],nums2[j]}});
                else if(sum<pq.top().first)
                {
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        // // as it is a max heap
        // reverse(ans.begin(),ans.end());
        // return ans;
    }
};


