// Approach : Using two arrays to store leftMax and rightMax for each index
// Kind of a DP approach

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax[n], rightMax[n];
        int ans = 0;
        
        // we are calculating leftMax and rightMax for each index
        // because we need to know the max height on left and right
        // so that we can calculate the water trapped at that index
        // which will be min(leftMax, rightMax) - height[i] (height of current index)


        leftMax[0] = height[0];
        for(int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        
        rightMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        
        for(int i = 0; i < n; i++) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return ans;
    }
};




// Approach : Using two pointers

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0, rightMax = 0;
        int left = 0, right = n-1;
        int ans = 0;
        
        while(left < right) {
            if(height[left] < height[right]) {
                if(height[left] >= leftMax) {
                    leftMax = height[left];
                }
                else {
                    ans += leftMax - height[left];
                }
                left++;
            }
            else {
                if(height[right] >= rightMax) {
                    rightMax = height[right];
                }
                else {
                    ans += rightMax - height[right];
                }
                right--;
            }
        }
        
        return ans;
    }
};
