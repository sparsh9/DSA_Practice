// Method 1 using Binary Search
class Solution {
    long long int binarySearch(long long int a){
        long long int s=0,e=a;
        long long int mid = s+(e-s)/2;
        long long int ans = -1;
        while(s<=e){
            long long int sq = mid*mid;
            if(sq == a)
                return mid;
            else if(sq > a)
                e = mid-1;
            else {
                s = mid + 1;
                ans = mid;
            }
            
            mid = s+(e-s)/2;
        }
        return ans;
    }
public:
    int mySqrt(int x) {
        return binarySearch(x);
    }
};

// Method 2 