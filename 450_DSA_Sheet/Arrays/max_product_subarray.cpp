
// Approach 1 using Kadane's Algorithm
// we will check from both left -> right and right -> left incase 
// if there may be a 0 in between the sequence, then we make the max_pro as 1
// and again start from next subarray after 0
// Also we are taking from both sides as if there are odd numbers of -ve numbers
// then in one of the cases the odd'th -ve number will be left in max_pro from either side.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_pro_current = INT_MIN;
        int max_pro = 1;
        // checking left to right
        for (int i=0;i<nums.size();i++){
            max_pro *= nums[i];
            max_pro_current = max(max_pro,max_pro_current);
            if(max_pro == 0)
                max_pro = 1;
        }
        // Till here we have checked 
        max_pro = 1;
        for(int i = nums.size()-1;i>=0;i--){
            max_pro *= nums[i];
            max_pro_current = max(max_pro,max_pro_current);
            if(max_pro ==0)
                max_pro = 1;
        }
        return max_pro_current;
        
    }
};


// Approach 2 using Dynamic Programming