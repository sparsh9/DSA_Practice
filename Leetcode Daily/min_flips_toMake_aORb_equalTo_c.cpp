// Approach 1 (using Bit Manipulation)
// a & 1 gives us the right most bit or the LSB.
// a >> 1 is right shift. Let a be 0101 then, a>>1 = 0010
// So here we will check bit by bit of the OR operation with the c and we will do right shift and &1 to get each and every bit.

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = 0;
        
        while( a != 0 || b != 0 || c != 0) {
            // if c's bit is 1 then either the a's or b's digit has to be 1
            if( (c & 1) == 1) {
                if((a & 1) == 0 && (b & 1) == 0) {
                    result++;
                }
            } 
            // if c's digit is 0, then both the a's and b's digit has to be 0
            else {
                if(a&1 == 1)
                    result++;
                if(b&1 == 1)
                    result++;
                // result += (a & 1) + (b & 1);
            }
            // Right Shift to move on to next bit
            a >>= 1;
            b >>= 1;
            c >>= 1;
            
        }
        
        return result;
    }
};

//Approach-2 (Using inbuild function)
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = (a | b) ^ c;
        return __builtin_popcount(result) + __builtin_popcount((a & b) & (result));
    }
};