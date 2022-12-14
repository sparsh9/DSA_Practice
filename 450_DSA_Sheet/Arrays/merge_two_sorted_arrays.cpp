// Approach 1 (using Merge Sort and extra space)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m+n);
        int i, j, k;
        i = j = k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
                ans[k++] = nums1[i++];
            else
                ans[k++] = nums2[j++];
        }
        while (i < m)
            ans[k++] = nums1[i++];
        while (j < n)
            ans[k++] = nums2[j++];
        
        for (int i = 0; i < m+n; i++)
        {
            nums1[i] = ans[i];
        }
    }
};

// Approach 2 (using Merge sort without extra space)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1; // Here we are using the remaining space in nums1 to store the new nums2 array during sort
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        while(i>=0)
            nums1[k--] = nums1[i--];
        while(j>=0)
            nums1[k--] = nums2[j--];
    }
}; 