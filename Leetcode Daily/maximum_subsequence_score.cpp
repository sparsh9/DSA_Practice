// Approach 1 (Using Priority Queue)
// Here the main idea is that we fix the right part of multiple which is the min(nums2 elements)
// Therefore , we are iterating over every kth element from left sorted (descending order) and assuming it to be the smallest
// Then we are using the Min_heap (priority queue) to add and remove the kth element from the sum(from the nums1) on our basis so that end result is maximised
// Therefore the top element will be the lowest and hence removing that everytime and adding the new one
// Therefore we are upgrading our currSum and ans respectively everytime.
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums1.size();i++){
            v.push_back(make_pair(nums2[i],nums1[i]));
        }
        sort(v.rbegin(),v.rend());

        long long int currSum = 0,ans =0;
        priority_queue<int,vector<int>,greater<int>> pq;

        // First Inserting only the k-1 terms only
        for(int i=0;i<k-1;i++){
            pq.push(v[i].second);
            currSum += v[i].second;
        }

        // Now Inserting the remaining kth term one by one

        for(int i=k-1;i<nums1.size();i++){
            currSum += v[i].second;
            pq.push(v[i].second);
            ans = max(ans,currSum*v[i].first);

            currSum -= pq.top();
            pq.pop();
        }
        return ans;
    }
};