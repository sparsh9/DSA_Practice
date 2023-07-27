class Solution {
public:
    typedef long long ll;

    bool possible(vector<int>& batteries, int n, ll mid){
        ll target_minitues = mid*n;
        ll sum = 0;
        for(auto &battery: batteries){
            sum += min(mid, (ll)battery);
            if(sum >= target_minitues) return true;
        }
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        ll left = *min_element(batteries.begin(), batteries.end());
        ll sum_total_batteries;
        for(auto &i: batteries) sum_total_batteries += i;

        ll right = sum_total_batteries/n;
        ll result = 0;  

        while(left <= right){
            ll mid = left + (right-left)/2;

            if(possible(batteries, n, mid)){
                result = mid;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return result;
    }
};