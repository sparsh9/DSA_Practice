bool isPossible (vector<int>& stalls,int k,int mid){
    int n=stalls.size();
    int cnt=1;
    int last_cow_loc=stalls[0];
    for(int i=0;i<n;i++){
        if(stalls[i]-last_cow_loc >= mid){
            cnt++;
            last_cow_loc = stalls[i];
            if(cnt >= k)
                return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int s=0,n=stalls.size();
    int e = stalls[n-1]-stalls[0];
    int ans=-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(isPossible(stalls,k,mid)){
            ans = mid;
            s=mid+1;
        }
        else
            e=mid-1; 
        mid = s+(e-s)/2;
    }
    return ans;
}