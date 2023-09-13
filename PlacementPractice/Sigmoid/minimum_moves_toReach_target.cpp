// Approach : Recursion (Thinking from back)

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if(target==1) return 0;
        if(maxDoubles == 0) return target-1;

        if(target%2==0){
            target = target/2;
            maxDoubles-=1;
           return 1 + minMoves(target,maxDoubles);
        }
        else {
            target-=1;
            return 1 + minMoves(target,maxDoubles);
        }
        return 0;
    }
};