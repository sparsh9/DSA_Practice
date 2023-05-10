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

// Approach 3 (Using max heap)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(),nums.end());
        // Removing all the k-1 greatest numbers
        for(int i=0;i<k-1;i++){
            q.pop();
        }
        // kth greatest number
        return q.top();
    }
};