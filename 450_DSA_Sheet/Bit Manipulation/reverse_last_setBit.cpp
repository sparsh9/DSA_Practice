// Function to reverse last set bit of a Number

#include <bits/stdc++.h>
using namespace std;

int reverseLastSetBitOfNumber(int n) {
    // we want to reverse last set bit, therefore we do xor operation
    // this will reverse set bit if it was set
    int ans = n ^ (n - 1);
    return ans;
}

int main() {
    int n = 5;
    cout << reverseLastSetBitOfNumber(n) << endl;
    return 0;
}