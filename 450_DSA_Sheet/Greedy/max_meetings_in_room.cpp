//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    static bool cmp(pair<int,int> a, pair<int,int>b){
        return a.second.first < b.second.first;
    }
    vector<int> maxMeetings(int N,vector<int> &s,vector<int> &f){
        vector<pair<int,pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({s[i],{f[i],i}});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int> ans;
        ans.push_back(v[0].second.second+1);
        int meetEnd = v[0].second.first;
        for(int i=1;i<n;i++){
            if(v[i].first > meetEnd){
                ans.push_back(i+1);
                meetEnd = v[i].second.first;
            }
        }
        return ans;  
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends