//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

// Approach 1 using set data structure
class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        set<int> sets;
        for(int i=0;i<n;i++){
            sets.insert(a[i]);
        }
        for(int i=0;i<m;i++){
            sets.insert(b[i]);
        }
        return sets.size();
    }
};

// Approach 2 using vector , sorting and then removing the duplicates

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends