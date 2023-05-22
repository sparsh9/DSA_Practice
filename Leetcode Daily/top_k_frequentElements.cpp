// Approach 1 using MaxHeap
// Time Complexity : O(nlogk)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int , int > m ;
    for( auto x : nums ){
                m[x]++ ;
    }
    priority_queue< pair<int , int> > pq ;
    for( auto x : m ) {
        pq.push({x.second , x.first }) ; 
    }
    vector<int> ans ;
    while(k--) {
        ans.push_back(pq.top().second ) ;
        pq.pop() ;
    }
    return ans ;
    }
};

// Approach 2 using bucket sort
// Next, a loop starts from the highest index (highest frequency) of the bucket vector and iterates until the size of res reaches k.
// Within the outer loop, an inner loop iterates through each element within the current bucket. 
// Elements are added to the res vector until k elements are collected or until there are no more elements in the current bucket.
// Time Complexity O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        for(auto x: nums) m[x]++;
        vector<int>res;
        vector<vector<int>>bucket(nums.size() + 1);
        for(auto p: m) bucket[p.second].push_back(p.first);
        for(int i = bucket.size() - 1; res.size() < k; i--)
            for(auto j: bucket[i]) res.push_back(j);
        return res;
    }
};