// Approach 1 (using inbuilt sort function)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return nums[n-k];
    }
};


// Approach 2 (Using Priority queue)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            
        }
        for(int i=0;i<k-1;i++)
        {
            pq.pop();
            
        }
        return pq.top();
    }
};