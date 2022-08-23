// Approach 1
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0)
            return false;
        else if(n==1)
            return true;
        return (ceil(log2(n))) == float(log2(n));
    }
};