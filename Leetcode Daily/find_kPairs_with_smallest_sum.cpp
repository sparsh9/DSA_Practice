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


// Approach 2 (using min heap)

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        // Custom comparator for the min heap
        auto cmp = [&](pair<int, int>& a, pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        // Push the first K pairs into the min heap
        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            pq.push({i, 0});
        }
        
        // Process the top K pairs from the min heap
        while (!pq.empty() && k--) {
            auto idx = pq.top();
            pq.pop();
            
            int i = idx.first;
            int j = idx.second;
            
            ans.push_back({nums1[i], nums2[j]});
            
            // Push the next pair from nums2 with the same nums1 element
            if (j + 1 < nums2.size()) {
                pq.push({i, j + 1});
            }
            
            // Push the next nums1 element with the smallest nums2 element
            if (j == 0 && i + 1 < nums1.size()) {
                pq.push({i + 1, j});
            }
        }
        
        return ans;
    }
};
