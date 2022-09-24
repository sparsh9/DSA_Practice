// // Approach 1 max,min approach
// // for every iteration checking the minimum difference(updating the min and max simultaneously)
// class Solution {
//   public:
//     int getMinDiff(int arr[], int n, int k) {
//         if(n == 1) return 0;
//         sort(arr,arr+n);
//         int diff = arr[n-1]-arr[0];
//         for(int i=1;i<n;i++){
//             if(arr[i]-k < 0) continue;
//             int maxi = max(arr[i]+k,maxi);
//             int mini = min(mini,arr[i]-k);
//             diff = min(diff , (maxi-mini));
//         }
//         return diff;
//     }
// };
//{ Driver Code Starts
// Initial template for C++



// Approach 2 
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
     
    if(n==1)return 0;
    
    sort(arr,arr+n);
    
    int diff=arr[n-1]-arr[0];
    
    for(int i=1;i<n;i++)
    {
        if(arr[i]-k<0)continue;
        
        int maxx=max(arr[i-1]+k,arr[n-1]-k);
        int minn=min(arr[0]+k,arr[i]-k);
        
        diff=min(diff,maxx-minn);
    }
    return diff;
    }
};