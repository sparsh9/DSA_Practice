// In this function we are checking the cow placements and possibility.
bool isPossible (vector<int>& stalls,int k,int mid){
    int n=stalls.size();
    int cnt=1; // as we have already placed a cow
    int last_cow_loc=stalls[0]; // initially placed the first cow at 1st position
    for(int i=0;i<n;i++){
        if(stalls[i]-last_cow_loc >= mid){
            cnt++;
            last_cow_loc = stalls[i]; // to place next cow
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
        // if suppose all cows can't be placed at max distance of 3 then 
        // it is obvious that cows can't be placed at distances more than 3 and 
        // due to this we have a search space and therefore we apply the concept of binary search.
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