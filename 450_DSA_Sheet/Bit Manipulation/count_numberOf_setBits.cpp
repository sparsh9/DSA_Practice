// Function to count number of set bits in a number

#include <bits/stdc++.h>
using namespace std;

int countNumberOfSetBits(int n){
    int count = 0;
    while(n > 0){
        // checks last bit as if set or not
        if((n & 1) == 1)
            count++;
        // continously right shifts so that the set bits moves rightwards and comes to rightmost position
        n = n >> 1;
    }
    return count;
}

int optimalSolution(int n){
    int cnt=0;
    while(n!= 0){
        n = n&(n-1);
        cnt++;
    }
    return cnt;
}


int main() {
    int n = 5;
    cout << countNumberOfSetBits(n) << endl;
    return 0;
}