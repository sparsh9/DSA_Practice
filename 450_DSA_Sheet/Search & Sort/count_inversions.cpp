// using Merge Sort Algorithm 
    typedef long long ll;
    ll ans = 0;
    long long int inversionCount(long long arr[], long long N)
    {
        ans = 0;
        mergeSort(arr, 0, N-1);
        return ans;
    }
    void mergeSort(ll arr[], ll lo, ll hi) {
        if(lo<hi) {
            ll mid = lo + (hi-lo)/2;
            mergeSort(arr, lo, mid);
            mergeSort(arr, mid+1, hi);
            merge(arr, lo, mid, hi);
        }
    }
    void merge(ll arr[], ll lo, ll mid, ll hi) {
        ll n1 = mid-lo+1, n2 = hi-mid;
        ll arr1[n1], arr2[n2];
        for(ll i=0; i<n1; i++) arr1[i] = arr[lo+i];
        for(ll i=0; i<n2; i++) arr2[i] = arr[mid+i+1];
        ll index1=0, index2=0, mainArrayStarting=lo;
        while(index1<n1 && index2<n2) {
            if(arr1[index1]<=arr2[index2]) arr[mainArrayStarting++] = arr1[index1++];
            else {
                // in the else condition if left one is bigger,then it is obvious that
                // all the elements to its right will also be bigger,therefore
                // we count all the remaining elements to the right in the left array.
                ans += n1 - index1; // Only this line added in merge sort code
                arr[mainArrayStarting++] = arr2[index2++];
            }
        }
        while(index1<n1) arr[mainArrayStarting++] = arr1[index1++];
        while(index2<n2) arr[mainArrayStarting++] = arr2[index2++];
    }