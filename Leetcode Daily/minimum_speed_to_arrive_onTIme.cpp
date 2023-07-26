// Approach using binary search
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int high = 1e7;
        int minspeed = -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            // checking if this speed is possible or not
            double time = 0;
            for(int i=0;i<dist.size()-1;i++){
                time += ceil((double)dist[i]/mid);
            }
            time += (double)dist[dist.size()-1]/mid;

            // if time is greater than hour then we need to increase the speed
            if(time <= hour)
                minspeed = mid,
                high = mid-1;
            // else we need to decrease the speed
            else
                low = mid+1;
        }

        return minspeed;
    }
};