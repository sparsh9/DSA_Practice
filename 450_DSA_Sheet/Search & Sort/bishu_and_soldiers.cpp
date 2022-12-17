// Method 1 using the upper bound function

// #include<iostream>
// #include<string>
// #include<vector>
// #include<bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     int a[n],pre_sum[n+1];
//     pre_sum[0] = 0;
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//         if(i>0)
//             pre_sum[i] = pre_sum[i-1]+a[i];
//     }
//     sort(a,a+n);
//     int q;
//     for(int i=0;i<q;i++){
//         int p;
//         cin>>p;
//         int ind = upper_bound(a,a+n,p)-a;
//         cout<<ind<<" "<<pre_sum[ind]<<endl;
//         // cout<<"Hello"<<endl;
//     }
//     return 0;
// }



// Method 2 
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vc vector<char>
#define xag ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int p;
    // cin>>p;
    int q;cin>>q;
    while(q--){
        int cs=0;
        cin>>p;
        int x=upper_bound(a,a+n,p)-a;
        for(int i=0;i<x;i++){
            cs+=a[i];
        }
        cout<<x<<" "<<cs<<endl;
    }
    return 0;
}