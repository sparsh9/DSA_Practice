// This koko eating bananas problem is similar to minimum speed to arrive on time problem.
// This will be solved using binary search.
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1e9;
        int minspeed = -1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            // checking if this speed is possible or not
            long long int time = 0;
            for(int i=0;i<piles.size();i++){
                time += ceil((double)piles[i]/mid);
            }
            
            // if time is greater than hour then we need to increase the speed
            if(time <= h)
                minspeed = mid,
                high = mid-1;
            // else we need to decrease the speed
            else
                low = mid+1;
        }
        
        return minspeed;
    }
};