// Approach 1 (Greedy)
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         int jumps = 0; //current jump
//         int currEnd = 0; // current end
//         int currFarthest = 0; // current farthest
//         for(int i=0; i<n-1; i++){
//             currFarthest = max(currFarthest, i+nums[i]); // update current farthest
//             if(i == currEnd){
//                 jumps++;
//                 currEnd = currFarthest;
//             }
//         }
//         return jumps;
//     }
// };
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int n = nums.size();
        if(nums[0] >= n-1) return 1;
        int jumps = 0; //current jump
        int currEnd = 0; // current end
        int currFarthest = 0; // current farthest
        while(currEnd < n-1){
            jumps++;
            int prevEnd = currEnd;
            for(int i=prevEnd; i<=currEnd; i++){
                currFarthest = max(currFarthest, i+nums[i]); // update current farthest
            }
            currEnd = currFarthest;
        }
        return jumps;
    }
};

// Approach 2 (Recursive) 
class Solution {
public:

    void checkValid(int i, int n, int &ans, int jumps, vector<int> &nums){
        if(i >= n-1){
            ans = min(ans, jumps);
            return;
        }
        for(int j=1; j<=nums[i]; j++){
            checkValid(i+j, n, ans, jumps+1, nums);
        }
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        checkValid(0, n, ans, 0, nums);
        return ans;  
    }
};