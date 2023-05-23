// Approach 1 using minHeap (instead of maxheap for better time complexity)
// Here we want that only k elements should be present in the heap at any time
// which are the k largest elements. So, if the size of the heap is less than k,
// then we simply push the element in the heap. But if the size of the heap is
// equal to k, then we check if the current element is greater than the top of
// the heap or not. If it is greater, then we pop the top of the heap and push
// the top of the heap is always smaller and other k-1 elements are greater than it
// so at last the top element is the kth largest element.
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minheap;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kth=k;
        for(int x:nums)
            add(x);
    }
    
    int add(int val) {
        if(minheap.size()<kth)
            minheap.push(val);
        else
        {
            if(val>minheap.top())
            {
                minheap.pop();
                minheap.push(val);
            }
        }
        return minheap.top();
    }
};