// Make a general template with input and output for a general function which I can use everytime for all my coding problems

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<queue>
#include<math.h>
#include<stdlib.h>
#include<deque>
using namespace std;

// Given an array of integers, what is the shortest increasing subsequence of the elements which when removed leaves behind only unique integers in the array?
// Complete the function below.
vector<int> solve(vector<int> &arr, int n){
    map<int, int> occ;
    for(int x: arr) occ[x]++;
    vector<int> extra;
    for(auto it: occ)
        if(it.second > 1)
            for(int i = 0; i+1<it.second; i++) 
                extra.push_back(it.first);
        
    if(extra.size() == 0) // returns a empty null vector
        return vector<int>();

    int i = 0, j = 0, m = extra.size();
    while(i<n and j<m){
        if(arr[i] == extra[j]) 
            j++;
        i++;
    }
    if(j != m) // it returns -1 vector
        return vector<int>(1, -1);

    return extra;
}

int main()
{
    int t = 1;
    cin>>t;
    while(t--)
    {
        // vector<int> nums = {1,2,1,3,1,4,5,2,4};
        vector<int> nums;
        nums.push_back(1);
        nums.push_back(2);
        nums.push_back(1);
        nums.push_back(3);
        nums.push_back(1);
        nums.push_back(4);
        nums.push_back(5);
        nums.push_back(2);
        nums.push_back(4);
        int k = 7;

        vector<int> ans = solve(nums,k);
        
        for(auto i:ans)
            cout<<i<<" ";

    }
    return 0;
}